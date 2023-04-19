//===----------------------------------------------------------------------===//
//
// Copyright 2020-2021 The ScaleHLS Authors.
//
//===----------------------------------------------------------------------===//

#include "scalehls/Dialect/HLS/Analysis.h"
#include "scalehls/Transforms/Utils.h"
#include "llvm/Support/Debug.h"

#define DEBUG_TYPE "dataflow-analysis"

using namespace mlir;
using namespace scalehls;
using namespace hls;

ComplexityAnalysis::ComplexityAnalysis(func::FuncOp func) {
  func.walk([&](NodeOp node) {
    auto nodeComplexity = calculateBlockComplexity(&node.getBody().front());
    if (!nodeComplexity.has_value()) {
      node.emitOpError("failed to calculate node complexity");
      return WalkResult::interrupt();
    }
    nodeComplexityMap.insert({node, nodeComplexity.value()});
    return WalkResult::advance();
  });
}

/// A helper to get the complexity of a schedule.
Optional<unsigned long>
ComplexityAnalysis::getScheduleComplexity(ScheduleOp schedule) const {
  unsigned long scheduleComplexity = 0;
  for (auto node : schedule.getOps<NodeOp>()) {
    if (!nodeComplexityMap.count(node))
      return Optional<unsigned long>();
    scheduleComplexity =
        std::max(scheduleComplexity, nodeComplexityMap.lookup(node));
  }
  return scheduleComplexity;
}

Optional<unsigned long>
ComplexityAnalysis::getNodeComplexity(NodeOp node) const {
  if (nodeComplexityMap.count(node))
    return nodeComplexityMap.lookup(node);
  return Optional<unsigned long>();
}

/// A helper to get the complexity of the given block
Optional<unsigned long>
ComplexityAnalysis::calculateBlockComplexity(Block *block) const {
  unsigned long complexity = 0;
  for (auto &op : block->getOperations()) {
    assert(!isa<NodeOp>(op) && "must not be node op");

    if (auto schedule = dyn_cast<ScheduleOp>(op)) {
      auto scheduleComplexity = getScheduleComplexity(schedule);
      if (!scheduleComplexity.has_value())
        return Optional<unsigned long>();
      complexity += scheduleComplexity.value();

    } else if (auto loop = dyn_cast<mlir::AffineForOp>(op)) {
      auto loopComplexity = calculateBlockComplexity(loop.getBody());
      auto loopTripCount = getAverageTripCount(loop);
      if (!loopComplexity.has_value() || !loopTripCount.has_value())
        return Optional<unsigned long>();
      complexity += loopTripCount.value() *
                    std::max((unsigned long)1, loopComplexity.value());

    } else if (auto ifOp = dyn_cast<mlir::AffineIfOp>(op)) {
      auto thenComplexity = calculateBlockComplexity(ifOp.getThenBlock());
      if (!thenComplexity.has_value())
        return Optional<unsigned long>();
      auto ifComplexity = thenComplexity.value();

      if (ifOp.hasElse()) {
        auto elseComplexity = calculateBlockComplexity(ifOp.getElseBlock());
        if (!elseComplexity.has_value())
          return Optional<unsigned long>();
        ifComplexity = std::max(ifComplexity, elseComplexity.value());
      }
      complexity += ifComplexity;
    }
    // else if (!op.hasTrait<OpTrait::IsTerminator>())
    //   complexity += 1;
  }
  return complexity;
}

static std::pair<SmallVector<int64_t>, SmallVector<int64_t>>
getBufferIndexDepthsAndStrides(NodeOp node, Value buffer) {
  if (node.hasHierarchy() ||
      !llvm::hasSingleElement(node.getOps<AffineForOp>()))
    return {};

  auto band = getNodeLoopBand(node);
  auto index = llvm::find(node.getOperands(), buffer) - node.operand_begin();
  assert(index != node.getNumOperands() && "invalid node or node buffer");
  auto localBuffer = node.getBody().getArgument(index);

  // Collect the buffer accessing map and indices in the current loop band.
  auto bufferMap = AffineMap::get(buffer.getContext());
  SmallVector<Value> bufferOperands;
  auto result = band.front().walk([&](Operation *op) {
    Value memref;
    auto map = AffineMap::get(buffer.getContext());
    SmallVector<Value> operands;
    if (auto read = dyn_cast<mlir::AffineReadOpInterface>(op)) {
      memref = read.getMemRef();
      map = read.getAffineMap();
      operands = read.getMapOperands();
    } else if (auto write = dyn_cast<mlir::AffineWriteOpInterface>(op)) {
      memref = write.getMemRef();
      map = write.getAffineMap();
      operands = write.getMapOperands();
    } else
      return WalkResult::advance();

    // If the op is not accessing the local buffer, skip it.
    if (memref != localBuffer)
      return WalkResult::advance();

    // Record the buffer accessing map and operands.
    if (bufferMap.isEmpty())
      bufferMap = map;
    if (bufferOperands.empty())
      bufferOperands = operands;

    // If the buffer accessing map or operands are not aligned, interrupt it.
    if (bufferMap != map || bufferOperands != operands)
      return WalkResult::interrupt();
    return WalkResult::advance();
  });

  if (result.wasInterrupted())
    return {};

  // Traverse each buffer dimension to determine the loop iv that is associated
  // with the index of the corresponding dimension.
  SmallVector<int64_t> depths;
  SmallVector<int64_t> strides;
  for (auto expr : bufferMap.getResults()) {
    // Get the flattened form of the expr, which is a sum of products in an
    // order of [dims, symbols, locals, constant].
    llvm::SmallVector<int64_t> flattenedExpr;
    if (failed(getFlattenedAffineExpr(expr, bufferMap.getNumDims(),
                                      bufferMap.getNumSymbols(),
                                      &flattenedExpr)))
      return {};

    SmallVector<std::tuple<int64_t, int64_t, bool, int64_t>> candidates;
    for (unsigned i = 0, e = bufferMap.getNumDims(); i < e; ++i) {
      auto loop = getForInductionVarOwner(bufferOperands[i]);
      if (flattenedExpr[i] == 0 || !loop)
        continue;

      unsigned depth = llvm::find(band, loop) - band.begin();
      if (depth != band.size())
        candidates.push_back(std::tuple(depth, flattenedExpr[i],
                                        isLoopParallel(loop),
                                        getAverageTripCount(loop).value_or(1)));
    }
    // TODO: Better support buffer index to resolve multiple loop ivs.
    // For now, we just pick the loop iv of parallel loop with the largest loop
    // trip count.
    llvm::sort(
        candidates, [](const std::tuple<int64_t, int64_t, bool, int64_t> &lhs,
                       const std::tuple<int64_t, int64_t, bool, int64_t> &rhs) {
          return std::get<2>(lhs) > std::get<2>(rhs) || // parallel loop first
                 (std::get<2>(lhs) == std::get<2>(rhs) &&
                  std::get<3>(lhs) > std::get<3>(rhs));
        });
    depths.push_back(std::get<0>(candidates.front()));
    strides.push_back(std::get<1>(candidates.front()));
  }
  return {depths, strides};
}

static std::pair<SmallVector<int64_t>, SmallVector<float>>
getPermuteMapAndScaleFactors(NodeOp node, SmallVector<int64_t> lhsDepths,
                             SmallVector<int64_t> rhsDepths,
                             SmallVector<int64_t> lhsStrides,
                             SmallVector<int64_t> rhsStrides) {
  assert(lhsDepths.size() == rhsDepths.size() && "incorrect number of depths");
  assert(lhsStrides.size() == rhsStrides.size() &&
         "incorrect number of strides");
  SmallVector<int64_t> permuteMap;
  SmallVector<float> scaleFactors;

  for (int64_t i = 0, e = getNodeLoopBand(node).size(); i < e; i++) {
    unsigned index = llvm::find(rhsDepths, i) - rhsDepths.begin();
    if (index != rhsDepths.size())
      if (lhsDepths[index] != -1 && lhsStrides[index] != -1 &&
          rhsStrides[index] != -1) {
        permuteMap.push_back(lhsDepths[index]);
        scaleFactors.push_back(lhsStrides[index] / (float)rhsStrides[index]);
        continue;
      }
    permuteMap.push_back(-1);
    scaleFactors.push_back(1.0);
  }
  return {permuteMap, scaleFactors};
}

CorrelationAnalysis::CorrelationAnalysis(func::FuncOp func) {
  func.walk([&](hls::BufferLikeInterface bufferOp) {
    auto buffer = bufferOp.getMemref();

    // TODO: Support node that has multiple loop bands.
    for (auto producerPair : getNestedProducers(buffer)) {
      auto producer = producerPair.first;
      auto producerBuffer = producerPair.second;
      auto [sourceDepths, sourceStrides] =
          getBufferIndexDepthsAndStrides(producer, producerBuffer);
      if (sourceDepths.empty())
        continue;

      for (auto consumerPair : getNestedConsumersExcept(buffer, producer)) {
        auto consumer = consumerPair.first;
        auto consumerBuffer = consumerPair.second;
        auto [targetDepths, targetStrides] =
            getBufferIndexDepthsAndStrides(consumer, consumerBuffer);
        if (targetDepths.empty())
          continue;

        auto [sourceToTargetMap, targetScaleFactors] =
            getPermuteMapAndScaleFactors(consumer, sourceDepths, targetDepths,
                                         sourceStrides, targetStrides);
        auto [targetToSourceMap, sourceScaleFactors] =
            getPermuteMapAndScaleFactors(producer, targetDepths, sourceDepths,
                                         targetStrides, sourceStrides);

        auto corr =
            Correlation(producer, consumer, bufferOp, producerBuffer,
                        consumerBuffer, sourceScaleFactors, targetScaleFactors,
                        sourceToTargetMap, targetToSourceMap);
        LLVM_DEBUG(
            // clang-format off
            llvm::dbgs() << "\n--------- Correlation ----------\n";
            llvm::dbgs() << "Buffer at " << bufferOp.getLoc() << ": "
                         << bufferOp << "\n";
            llvm::dbgs() << "Producer at " << producer.getLoc() << ":\n"
                         << producer << "\n";
            llvm::dbgs() << "Consumer at " << consumer.getLoc() << ":\n"
                         << consumer << "\n";
            llvm::dbgs() << "Source-to-target Map: { ";
            for (auto i : sourceToTargetMap)
              llvm::dbgs() << i << " ";
            llvm::dbgs() << "}\n";
            llvm::dbgs() << "Target-to-source Map: { ";
            for (auto i : targetToSourceMap)
              llvm::dbgs() << i << " ";
            llvm::dbgs() << "}\n";
            // clang-format on
        );

        // correlations.push_back(corr);
        nodeCorrelationMap[producer].push_back(corr);
        nodeCorrelationMap[consumer].push_back(corr);
      }
    }
    return WalkResult::advance();
  });
}
