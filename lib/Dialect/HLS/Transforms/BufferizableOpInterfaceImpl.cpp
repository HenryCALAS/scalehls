//===----------------------------------------------------------------------===//
//
// Copyright 2020-2021 The ScaleHLS Authors.
//
//===----------------------------------------------------------------------===//

#include "scalehls/Dialect/HLS/Transforms/BufferizableOpInterfaceImpl.h"
#include "mlir/Dialect/Bufferization/IR/BufferizableOpInterface.h"
#include "mlir/Dialect/Bufferization/IR/Bufferization.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Interfaces/ViewLikeInterface.h"
#include "scalehls/Dialect/HLS/IR/HLS.h"

using namespace mlir;
using namespace bufferization;
using namespace scalehls;
using namespace hls;

/// Bufferization of dispatch/task operation. Replace with a new dispatch/task
/// that yields memrefs.
template <typename OpType>
struct DispatchOrTaskOpInterface
    : public BufferizableOpInterface::ExternalModel<
          DispatchOrTaskOpInterface<OpType>, OpType> {
  /// Dispatch/task do not have tensor OpOperands. Thus, no OpOperand will be
  /// bufferized to memory read/write or be aliased to any returned values.
  AliasingValueList getAliasingValues(Operation *op, OpOperand &opOperand,
                                      const AnalysisState &state) const {
    return {};
  }

  // Dispatch/task do not have tensor OpOperands. The yielded value can be any
  // SSA value that is in scope. To allow for use-def chain traversal in the
  // analysis, the yielded value is aliasing with the result.
  AliasingOpOperandList
  getAliasingOpOperands(Operation *op, Value value,
                        const AnalysisState &state) const {
    OpOperand *operand = &cast<OpType>(op).getYieldOp()->getOpOperand(
        cast<OpResult>(value).getResultNumber());
    return {{operand, BufferRelation::Equivalent}};
  }

  LogicalResult bufferize(Operation *op, RewriterBase &rewriter,
                          const BufferizationOptions &options) const {
    OpBuilder::InsertionGuard g(rewriter);
    auto concreteOp = cast<OpType>(op);

    // Compute bufferized result types.
    SmallVector<Type> newTypes;
    for (Value result : concreteOp.getResults()) {
      if (!result.getType().isa<TensorType>()) {
        newTypes.push_back(result.getType());
        continue;
      }
      auto bufferType = bufferization::getBufferType(result, options);
      if (failed(bufferType))
        return failure();
      newTypes.push_back(*bufferType);
    }

    // Create new dispatch/task op.
    rewriter.setInsertionPoint(concreteOp);
    auto newOp = rewriter.create<OpType>(concreteOp.getLoc(), newTypes);
    rewriter.inlineRegionBefore(concreteOp.getBody(), newOp.getBody(),
                                newOp.getBody().end());

    // Replace dispatch/task op results.
    replaceOpWithBufferizedValues(rewriter, concreteOp, newOp->getResults());
    return success();
  }

  FailureOr<BaseMemRefType>
  getBufferType(Operation *op, Value value, const BufferizationOptions &options,
                SmallVector<Value> &invocationStack) const {
    assert(value.getDefiningOp() == op && "invalid value");
    auto yieldedValue = cast<OpType>(op).getYieldOp().getOperand(
        value.cast<OpResult>().getResultNumber());

    if (auto bufferType =
            yieldedValue.getType().template dyn_cast<BaseMemRefType>())
      return bufferType;

    auto maybeBufferType =
        bufferization::getBufferType(yieldedValue, options, invocationStack);
    if (failed(maybeBufferType))
      return failure();
    return *maybeBufferType;
  }
};

/// Bufferization of fdf.yield operation.
struct YieldOpInterface
    : public BufferizableOpInterface::ExternalModel<YieldOpInterface, YieldOp> {
  bool bufferizesToAllocation(Operation *op, Value value) const { return true; }

  bool bufferizesToMemoryRead(Operation *op, OpOperand &opOperand,
                              const AnalysisState &state) const {
    return true;
  }
  bool bufferizesToMemoryWrite(Operation *op, OpOperand &opOperand,
                               const AnalysisState &state) const {
    return false;
  }

  AliasingValueList getAliasingValues(Operation *op, OpOperand &opOperand,
                                      const AnalysisState &state) const {
    if (isa<DispatchOp, TaskOp>(op->getParentOp()))
      return {{op->getParentOp()->getResult(opOperand.getOperandNumber()),
               BufferRelation::Equivalent}};
    return {};
  }

  bool mustBufferizeInPlace(Operation *op, OpOperand &opOperand,
                            const AnalysisState &state) const {
    // Yield operands always bufferize inplace. Otherwise, an alloc + copy may
    // be generated inside the block. We should not return/yield allocations
    // when possible.
    return true;
  }

  LogicalResult bufferize(Operation *op, RewriterBase &rewriter,
                          const BufferizationOptions &options) const {
    OpBuilder::InsertionGuard g(rewriter);
    auto yield = cast<YieldOp>(op);
    auto parent = yield->getParentOp();

    // Traverse and bufferize each operand of the yield operation.
    for (auto operand : yield.getOperands()) {
      if (!operand.getType().isa<TensorType>())
        continue;

      auto maybeBuffer = getBuffer(rewriter, operand, options);
      auto maybeType = bufferization::getBufferType(operand, options);
      if (failed(maybeBuffer) || failed(maybeType))
        continue;

      // For now, we always generate an explicit copy to handle view-like
      // operations. This is not efficient but it's safe.
      if (auto view = maybeBuffer->getDefiningOp<ViewLikeOpInterface>()) {
        rewriter.setInsertionPoint(parent);
        auto localBuffer = options.createAlloc(
            rewriter, yield.getLoc(), maybeType->cast<MemRefType>(), {});
        if (failed(localBuffer))
          return failure();

        rewriter.setInsertionPoint(yield);
        if (failed(options.createMemCpy(rewriter, yield.getLoc(), *maybeBuffer,
                                        *localBuffer)))
          return failure();

        rewriter.replaceUsesWithIf(operand, *localBuffer, [&](OpOperand &use) {
          return use.getOwner() == yield;
        });
      } else {
        rewriter.setInsertionPoint(yield);
        auto replacement = rewriter.create<bufferization::ToMemrefOp>(
            yield.getLoc(), *maybeType, operand);
        rewriter.replaceUsesWithIf(operand, replacement, [&](OpOperand &use) {
          return use.getOwner() == yield;
        });
      }
    }
    return success();
  }
};

/// Bufferization of fdf.alloc_tensor operation.
struct AllocTensorOpInterface
    : public BufferizableOpInterface::ExternalModel<AllocTensorOpInterface,
                                                    hls::AllocTensorOp> {
  bool bufferizesToAllocation(Operation *op, Value value) const { return true; }

  bool resultBufferizesToMemoryWrite(Operation *op, OpResult opResult,
                                     const AnalysisState &state) const {
    return false;
  }

  AliasingValueList getAliasingValues(Operation *op, OpOperand &opOperand,
                                      const AnalysisState &state) const {
    // This is a new allocation. It does not alias with any other buffer.
    return {};
  }

  LogicalResult bufferize(Operation *op, RewriterBase &rewriter,
                          const BufferizationOptions &options) const {
    OpBuilder::InsertionGuard g(rewriter);
    auto allocTensor = cast<hls::AllocTensorOp>(op);

    // Nothing to do for dead AllocTensorOps.
    if (allocTensor->getUses().empty()) {
      rewriter.eraseOp(allocTensor);
      return success();
    }

    // Create memory allocation.
    auto maybeType =
        bufferization::getBufferType(allocTensor.getResult(), options);
    if (failed(maybeType))
      return failure();

    FailureOr<Value> buffer = options.createAlloc(
        rewriter, allocTensor.getLoc(), maybeType->cast<MemRefType>(), {});
    if (failed(buffer))
      return failure();

    // Handle initial value.
    if (auto initValue = allocTensor.getInitValue()) {
      auto initValueOp = initValue.getDefiningOp<arith::ConstantOp>();
      auto bufferOp = buffer->getDefiningOp<BufferOp>();
      if (!initValueOp || !bufferOp)
        return failure();
      bufferOp.setInitValueAttr(initValueOp.getValue());
    }

    // Replace op.
    replaceOpWithBufferizedValues(rewriter, allocTensor, *buffer);
    return success();
  }

  FailureOr<BaseMemRefType>
  getBufferType(Operation *op, Value value, const BufferizationOptions &options,
                SmallVector<Value> &invocationStack) const {
    auto allocTensor = cast<hls::AllocTensorOp>(op);
    assert(value == allocTensor.getResult() && "invalid value");

    // Compute memory space of this allocation.
    Attribute memorySpace;
    if (options.defaultMemorySpace.has_value())
      memorySpace = *options.defaultMemorySpace;
    else
      return allocTensor.emitError("could not infer memory space");

    return getMemRefTypeWithStaticIdentityLayout(allocTensor.getType(),
                                                 memorySpace);
  }
};

void mlir::scalehls::hls::registerBufferizableOpInterfaceExternalModels(
    DialectRegistry &registry) {
  registry.addExtension(+[](MLIRContext *ctx, HLSDialect *dialect) {
    DispatchOp::attachInterface<DispatchOrTaskOpInterface<DispatchOp>>(*ctx);
    TaskOp::attachInterface<DispatchOrTaskOpInterface<TaskOp>>(*ctx);
    YieldOp::attachInterface<YieldOpInterface>(*ctx);
    hls::AllocTensorOp::attachInterface<AllocTensorOpInterface>(*ctx);
  });
}
