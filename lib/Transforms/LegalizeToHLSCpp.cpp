//===----------------------------------------------------------------------===//
//
// Copyright 2020-2021 The ScaleHLS Authors.
//
//===----------------------------------------------------------------------===//

#include "mlir/Dialect/Affine/Analysis/AffineAnalysis.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/Vector/IR/VectorOps.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "scalehls/Transforms/Passes.h"
#include "scalehls/Transforms/Utils.h"

using namespace mlir;
using namespace scalehls;
using namespace hlscpp;

namespace {
/// Simple memref load to affine load raising.
struct MemrefLoadRewritePattern : public OpRewritePattern<memref::LoadOp> {
  using OpRewritePattern<memref::LoadOp>::OpRewritePattern;

  LogicalResult matchAndRewrite(memref::LoadOp load,
                                PatternRewriter &rewriter) const override {
    if (llvm::all_of(load.getIndices(), [&](Value operand) {
          return isValidDim(operand) || isValidSymbol(operand);
        })) {
      rewriter.replaceOpWithNewOp<AffineLoadOp>(load, load.memref(),
                                                load.getIndices());
      return success();
    }
    return failure();
  }
};
} // namespace

namespace {
/// Simple memref store to affine store raising.
struct MemrefStoreRewritePattern : public OpRewritePattern<memref::StoreOp> {
  using OpRewritePattern<memref::StoreOp>::OpRewritePattern;

  LogicalResult matchAndRewrite(memref::StoreOp store,
                                PatternRewriter &rewriter) const override {
    if (llvm::all_of(store.getIndices(), [&](Value operand) {
          return isValidDim(operand) || isValidSymbol(operand);
        })) {
      rewriter.replaceOpWithNewOp<AffineStoreOp>(
          store, store.value(), store.memref(), store.getIndices());
      return success();
    }
    return failure();
  }
};
} // namespace

bool scalehls::applyLegalizeToHLSCpp(FuncOp func, bool isTopFunc,
                                     bool axiInterf) {
  auto builder = OpBuilder(func);

  // We constrain functions to only contain one block.
  // TODO: Make sure there's no memref store/load or scf operations?
  if (!llvm::hasSingleElement(func))
    func.emitError("has zero or more than one basic blocks.");

  // Set top function attribute.
  if (isTopFunc)
    setTopFuncAttr(func);

  // Set parallel attribute to each loop that is applicable.
  func.walk([&](AffineForOp loop) {
    if (isLoopParallel(loop))
      setParallelAttr(loop);
  });

  if (axiInterf) {
    // Convert each argument memory kind to DRAM and buffer each of them.
    for (auto arg : func.getArguments()) {
      if (auto type = arg.getType().dyn_cast<MemRefType>()) {
        arg.setType(MemRefType::get(type.getShape(), type.getElementType(),
                                    type.getLayout().getAffineMap(),
                                    (unsigned)MemoryKind::DRAM));
      }
    }

    // Finally, update the type of the function.
    func.setType(builder.getFunctionType(func.front().getArgumentTypes(),
                                         func.getResultTypes()));
  }

  // Insert AssignOp when an arguments or result of ConstantOp are directly
  // connected to ReturnOp.
  auto returnOp = func.front().getTerminator();
  builder.setInsertionPoint(returnOp);
  unsigned idx = 0;
  for (auto operand : returnOp->getOperands()) {
    if (operand.dyn_cast<BlockArgument>()) {
      auto value = builder.create<AssignOp>(returnOp->getLoc(),
                                            operand.getType(), operand);
      returnOp->setOperand(idx, value);
    } else if (isa<arith::ConstantOp>(operand.getDefiningOp())) {
      auto value = builder.create<AssignOp>(returnOp->getLoc(),
                                            operand.getType(), operand);
      returnOp->setOperand(idx, value);
    }
    ++idx;
  }

  mlir::RewritePatternSet patterns(func.getContext());
  patterns.add<MemrefLoadRewritePattern>(func.getContext());
  patterns.add<MemrefStoreRewritePattern>(func.getContext());
  vector::populateVectorTransferLoweringPatterns(patterns);
  (void)applyPatternsAndFoldGreedily(func, std::move(patterns));

  return true;
}

namespace {
struct LegalizeToHLSCpp : public LegalizeToHLSCppBase<LegalizeToHLSCpp> {
  LegalizeToHLSCpp() = default;
  LegalizeToHLSCpp(std::string hlsTopFunc, bool hlsAxiInterf) {
    topFunc = hlsTopFunc;
    axiInterf = hlsAxiInterf;
  }

  void runOnOperation() override {
    auto func = getOperation();
    auto isTop = func.getName() == topFunc;
    applyLegalizeToHLSCpp(func, isTop, isTop && axiInterf);
  }
};
} // namespace

std::unique_ptr<Pass> scalehls::createLegalizeToHLSCppPass() {
  return std::make_unique<LegalizeToHLSCpp>();
}
std::unique_ptr<Pass>
scalehls::createLegalizeToHLSCppPass(std::string hlsTopFunc,
                                     bool hlsAxiInterf) {
  return std::make_unique<LegalizeToHLSCpp>(hlsTopFunc, hlsAxiInterf);
}
