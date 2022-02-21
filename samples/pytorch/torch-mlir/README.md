## Using Torch-MLIR front-end
If you have installed [Torch-MLIR](https://github.com/llvm/torch-mlir), you should be able to run the following test:
```sh
$ cd resnet18

$ # Parse PyTorch model to Linalg dialect (with mlir_venv activated).
$ python3 export_resnet18_mlir.py | torch-mlir-opt \
    -torchscript-module-to-torch-backend-pipeline="optimize=true" \
    -torch-backend-to-linalg-on-tensors-backend-pipeline="optimize=true" \
    -canonicalize > resnet18.mlir
```
