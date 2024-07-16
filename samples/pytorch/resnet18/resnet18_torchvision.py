import sys
import torch
import torchvision.models as models
from torch_mlir import torchscript

resnet18 = models.resnet18(weights=models.ResNet18_Weights.DEFAULT)
resnet18.train(False)
module = torchscript.compile(resnet18, torch.ones(
    1, 3, 128, 128), output_type="linalg-on-tensors")

print(module)
