set -x
set -e

if [[ -n "$CONDA_PREFIX" ]]; then
  echo "Execute in a Conda environment: $CONDA_PREFIX"
  python3 mobilenet.py > mobilenet.mlir
  scalehls-opt mobilenet.mlir \
    -scaleflow-pytorch-pipeline="top-func=forward loop-tile-size=8 loop-unroll-factor=4" \
    | scalehls-translate -scalehls-emit-hlscpp > mobilenet.cpp
else
  echo "You are not in a Conda environment."
  exit 1
fi