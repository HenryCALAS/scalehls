#!/usr/bin/env bash

SCALEHLS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
if [ -n "${PATH}" ]; then
  export PATH=$PATH:$SCALEHLS_DIR/build/bin:$SCALEHLS_DIR/polygeist/build/bin
else
  export PATH=$SCALEHLS_DIR/build/bin:$SCALEHLS_DIR/polygeist/build/bin
fi
if [ -n "${PYTHONPATH}" ]; then
  export PYTHONPATH=$PYTHONPATH:$SCALEHLS_DIR/build/tools/scalehls/python_packages/scalehls_core:\
$SCALEHLS_DIR/torch-mlir/build/tools/torch-mlir/python_packages/torch_mlir:$SCALEHLS_DIR/torch-mlir/examples
else
  export PYTHONPATH=$SCALEHLS_DIR/build/tools/scalehls/python_packages/scalehls_core:\
$SCALEHLS_DIR/torch-mlir/build/tools/torch-mlir/python_packages/torch_mlir:/$SCALEHLS_DIR/torch-mlir/examples
fi