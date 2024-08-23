set -x
set -e

if [[ -n "$CONDA_PREFIX" ]]; then
  echo "Execute in a Conda environment: $CONDA_PREFIX"
  python3 hls_test.py > nanodet.mlir
  scalehls-opt nanodet.mlir \
    -scaleflow-pytorch-pipeline="top-func=forward loop-tile-size=8 loop-unroll-factor=4" \
    | scalehls-translate -scalehls-emit-hlscpp > nanodet.cpp
else
  echo "You are not in a Conda environment."
  exit 1
fi
