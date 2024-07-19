import torch
import torch.nn as nn
import torch.nn.functional as F

from shufflenetv2 import ShuffleNetV2
from pan import GhostPAN
from head import NanoDetPlusHead

class NanoDetPlus(nn.Module):
    def __init__(self):
        super(NanoDetPlus, self).__init__()
        self.backbone = ShuffleNetV2()
        self.fpn = GhostPAN()
        self.head = NanoDetPlusHead()

    def forward(self, x):
        x = self.backbone(x)
        x = self.fpn(x)
        x = self.head(x)
        return x

