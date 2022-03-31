//===----------------------------------------------------------------------===//
//
// Copyright 2020-2021 The ScaleHLS Authors.
//
//===----------------------------------------------------------------------===//

#ifndef SCALEHLS_TRANSFORMS_PASSES_H
#define SCALEHLS_TRANSFORMS_PASSES_H

#include "mlir/Pass/Pass.h"
#include <memory>

namespace mlir {
class Pass;
} // namespace mlir

namespace mlir {
namespace scalehls {

void registerScaleHLSDSEPipeline();
void registerScaleHLSPyTorchPipeline();
void registerScaleHLSTestPipeline();
void registerTransformsPasses();

/// QoR estimation and DSE passes.
std::unique_ptr<Pass> createQoREstimationPass();
std::unique_ptr<Pass> createQoREstimationPass(std::string qorTargetSpec);
std::unique_ptr<Pass> createMultipleLevelDSEPass();
std::unique_ptr<Pass> createMultipleLevelDSEPass(std::string dseTargetSpec);

/// Graph optimization passes.
std::unique_ptr<Pass> createFakeQuantizePass();
std::unique_ptr<Pass> createSimplifyTosaGraphPass();
std::unique_ptr<Pass> createShareTensorOperationPass();
std::unique_ptr<Pass> createHeuristicNodeFusionPass();
std::unique_ptr<Pass> createFuncDataflowPass();
std::unique_ptr<Pass> createFuncDataflowPass(unsigned dataflowGran,
                                             bool dataflowBalance = true);
std::unique_ptr<Pass> createTosaToLinalgCleanupPass();

/// Runtime-related passes.
std::unique_ptr<Pass> createCreateRuntimeMainPass();
std::unique_ptr<Pass> createCreateRuntimeMainPass(std::string hlsTopFunc);

/// HLSCpp legalization pass.
std::unique_ptr<Pass> createLegalizeToHLSCppPass();
std::unique_ptr<Pass> createLegalizeToHLSCppPass(std::string hlsTopFunc,
                                                 bool hlsAxiInterf = false);

/// Loop optimization passes.
std::unique_ptr<Pass>
createConvertCopyToAffineLoopsPass(bool convertInternCopyOnly = true);
std::unique_ptr<Pass> createMaterializeReductionPass();
std::unique_ptr<Pass> createAffineLoopPerfectionPass();
std::unique_ptr<Pass> createRemoveVariableBoundPass();
std::unique_ptr<Pass> createAffineLoopOrderOptPass();
std::unique_ptr<Pass> createAffineLoopTilePass();
std::unique_ptr<Pass> createAffineLoopTilePass(unsigned loopTileSize);
std::unique_ptr<Pass> createAffineLoopUnrollJamPass();
std::unique_ptr<Pass>
createAffineLoopUnrollJamPass(unsigned loopUnrollSize,
                              bool unrollPointLoopOnly = false);
std::unique_ptr<Pass> createAffineLoopDataflowPass();
std::unique_ptr<Pass> createAffineLoopDataflowPass(unsigned dataflowGran,
                                                   bool dataflowBalance = true);
std::unique_ptr<Pass> createSimplifyAffineIfPass();

/// Memory optimization passes.
std::unique_ptr<Pass> createCreateMemrefSubviewPass();
std::unique_ptr<Pass> createPromoteBufferPass();
std::unique_ptr<Pass> createAffineStoreForwardPass();
std::unique_ptr<Pass> createSimplifyMemrefAccessPass();
std::unique_ptr<Pass> createRaiseImplicitCopyPass();
std::unique_ptr<Pass> createReduceInitialIntervalPass();

void registerScaleHLSPassPipeline();
/// Directive optimization passes.
std::unique_ptr<Pass> createFuncPipeliningPass();
std::unique_ptr<Pass> createLoopPipeliningPass();
std::unique_ptr<Pass> createArrayPartitionPass();
std::unique_ptr<Pass> createCreateHLSCppPrimitivePass();

/// Other passes.
std::unique_ptr<Pass> createPreserveUnoptimizedPass();

#define GEN_PASS_CLASSES
#include "scalehls/Transforms/Passes.h.inc"

} // namespace scalehls
} // namespace mlir

#endif // SCALEHLS_TRANSFORMS_PASSES_H
