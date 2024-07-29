set -x
set -e

if [[ -n "$CONDA_PREFIX" ]]; then
  echo "Execute in a Conda environment: $CONDA_PREFIX"
  python3 resnet18_torchvision.py > resnet18.mlir
  scalehls-opt resnet18.mlir \
    -scaleflow-pytorch-pipeline="top-func=forward loop-tile-size=8 loop-unroll-factor=4" \
    | scalehls-translate -scalehls-emit-hlscpp > resnet18_torchvision.cpp
else
  echo "You are not in a Conda environment."
  exit 1
fi