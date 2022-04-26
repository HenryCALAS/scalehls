//===----------------------------------------------------------------------===//
//
// Copyright 2020-2021 The ScaleHLS Authors.
//
//===----------------------------------------------------------------------===//

#include "scalehls-c/HLS.h"
#include "mlir/CAPI/Registration.h"
#include "scalehls/Dialect/HLS/HLS.h"

using namespace mlir;
using namespace scalehls;

MLIR_DEFINE_CAPI_DIALECT_REGISTRATION(HLS, hls, hls::HLSDialect)
