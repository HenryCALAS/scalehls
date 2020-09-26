//===------------------------------------------------------------*- C++ -*-===//
//
//===----------------------------------------------------------------------===//

#include "Analysis/QoREstimation.h"
#include "Analysis/Passes.h"
#include "Dialect/HLSCpp/HLSCpp.h"
#include "INIReader.h"
#include "Visitor.h"

using namespace std;
using namespace mlir;
using namespace scalehls;
using namespace hlscpp;

//===----------------------------------------------------------------------===//
// HLSCppAnalyzer Class Definition
//===----------------------------------------------------------------------===//

bool HLSCppAnalyzer::visitOp(AffineForOp op) { return true; }

bool HLSCppAnalyzer::visitOp(AffineParallelOp op) { return true; }

bool HLSCppAnalyzer::visitOp(AffineIfOp op) { return true; }

/// This method will update all parameters except IterLatency, Latency, LUT,
/// BRAM, and DSP through static analysis.
void HLSCppAnalyzer::analyzeOperation(Operation *op) {
  if (dispatchVisitor(op))
    return;

  op->emitError("can't be correctly analyzed.");
}

void HLSCppAnalyzer::analyzeFunc(FuncOp func) { procParam.init(func); }

void HLSCppAnalyzer::analyzeBlock(Block &block) {
  for (auto &op : block)
    analyzeOperation(&op);
}

/// This method is a wrapper for recursively calling operation analyzer.
void HLSCppAnalyzer::analyzeModule(ModuleOp module) {
  for (auto &op : module) {
    if (auto func = dyn_cast<FuncOp>(op)) {
      analyzeFunc(func);
    } else if (!isa<ModuleTerminatorOp>(op))
      op.emitError("is unsupported operation.");
  }
}

//===----------------------------------------------------------------------===//
// QoREstimator Class Definition
//===----------------------------------------------------------------------===//

/// Estimator constructor.
QoREstimator::QoREstimator(ProcParam &procParam, MemParam &memParam,
                           string targetSpecPath, string opLatencyPath)
    : procParam(procParam), memParam(memParam) {
  INIReader targetSpec(targetSpecPath);
  if (targetSpec.ParseError())
    llvm::outs() << "error: target spec file parse fail, please refer to "
                    "--help option and pass in correct file path\n";

  INIReader opLatency(opLatencyPath);
  if (opLatency.ParseError())
    llvm::outs() << "error: Op latency file parse fail, please refer to "
                    "--help option and pass in correct file path\n";

  auto freq = targetSpec.Get("config", "frequency", "200MHz");
  auto latency = opLatency.GetInteger(freq, "op", 0);
  llvm::outs() << latency << "\n";
}

/// For now, estimation for unrolled loops are following the analytical model
/// of COMBA, which is suspected to be wrong. Meanwhile, we assume the absence
/// of function call in the loop body.
///
/// This method will update ProcParam::IterLatency and ProcParam::Latency of the
/// current affine for loop.
bool QoREstimator::visitOp(AffineForOp op) {
  auto &body = op.getLoopBody();
  if (body.getBlocks().size() != 1)
    op.emitError("has zero or more than one basic blocks.");

  // Recursively estimate latency of sub-elements, including functions and
  // loops. These sub-elements will be considered as a normal node in the CDFG
  // for function latency estimzation.
  estimateBlock(body.front());

  // Estimate iteration latency.
  unsigned iterLatency = searchLongestPath(body.front());
  procParam.set(op, ProcParamKind::IterLatency, iterLatency);

  // Estimate affine for loop latency.
  unsigned latency = iterLatency;
  if (procParam.get(op, ProcParamKind::LoopBound) != 1)
    latency *= procParam.get(op, ProcParamKind::LoopBound) *
               procParam.get(op, ProcParamKind::UnrollFactor);
  procParam.set(op, ProcParamKind::Latency, latency);
}

bool QoREstimator::visitOp(AffineParallelOp op) { return true; }

bool QoREstimator::visitOp(AffineIfOp op) { return true; }

/// This method recursively update the time stamp of all values (1) directly
/// generated as result by the current operation or (2) generated by any
/// operations insided of the region held by the current operation.
void QoREstimator::updateValueTimeStamp(
    Operation *currentOp, unsigned opTimeStamp,
    DenseMap<Value, unsigned> &valueTimeStampMap) {
  for (auto result : currentOp->getResults())
    valueTimeStampMap[result] = opTimeStamp;
  for (auto &region : currentOp->getRegions()) {
    for (auto &op : region.front())
      updateValueTimeStamp(&op, opTimeStamp, valueTimeStampMap);
  }
}

/// This method will search the longest path in a DAG block using a ASAP (As
/// Soon As Possible) manner. Loop, function, if, and other operation owning
/// regions will be considered as a whole.
unsigned QoREstimator::searchLongestPath(Block &block) {
  DenseMap<Value, unsigned> valueTimeStampMap;
  unsigned blockTimeStamp = 0;

  for (auto &op : block) {
    unsigned opTimeStamp = 0;

    // Add the latest ready time among all predecessors.
    for (auto operand : op.getOperands())
      opTimeStamp = max(opTimeStamp, valueTimeStampMap[operand]);

    // Add latency of the current operation.
    if (auto subAffineFor = dyn_cast<AffineForOp>(op))
      opTimeStamp += procParam.get(subAffineFor, ProcParamKind::Latency);
    else
      opTimeStamp += 1;
    blockTimeStamp = max(blockTimeStamp, opTimeStamp);

    // Update ready time of each value generated by the current operation.
    updateValueTimeStamp(&op, opTimeStamp, valueTimeStampMap);
  }
  return blockTimeStamp;
}

void QoREstimator::estimateOperation(Operation *op) {
  if (dispatchVisitor(op))
    return;

  op->emitError("can't be correctly estimated.");
}

/// For now, function pipelining and task-level dataflow optimizations are not
/// considered for simplicity. Meanwhile, we assume the absence of function call
/// in the loop body.
///
/// This method will update ProcParam::Latency of the current function.
void QoREstimator::estimateFunc(FuncOp func) {
  if (func.getBlocks().size() != 1)
    func.emitError("has zero or more than one basic blocks.");

  estimateBlock(func.front());

  // Estimate function latency.
  unsigned latency = searchLongestPath(func.front());
  procParam.set(func, ProcParamKind::Latency, latency);
}

void QoREstimator::estimateBlock(Block &block) {
  for (auto &op : block)
    estimateOperation(&op);
}

void QoREstimator::estimateModule(ModuleOp module) {
  for (auto &op : module) {
    if (auto func = dyn_cast<FuncOp>(op)) {
      estimateFunc(func);
    } else if (!isa<ModuleTerminatorOp>(op))
      op.emitError("is unsupported operation.");
  }
}

//===----------------------------------------------------------------------===//
// Entry of scalehls-opt
//===----------------------------------------------------------------------===//

namespace {
struct QoREstimation : public QoREstimationBase<QoREstimation> {
  void runOnOperation() override {
    ProcParam procParam;
    MemParam memParam;

    // Extract all static parameters and current pragma configurations.
    HLSCppAnalyzer analyzer(procParam, memParam);
    analyzer.analyzeModule(getOperation());

    // Estimate performance and resource utilization.
    QoREstimator estimator(analyzer.procParam, analyzer.memParam, targetSpec,
                           opLatency);
    estimator.estimateModule(getOperation());
  }
};
} // namespace

std::unique_ptr<mlir::Pass> scalehls::createQoREstimationPass() {
  return std::make_unique<QoREstimation>();
}
