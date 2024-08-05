import torch.nn as nn
import torch.nn.functional as F

from shufflenetv2 import ShuffleNetV2
from pan import GhostPAN
from head import NanoDetPlusHead

class NanoDetPlus(nn.Module):
    def __init__(self):
        super(NanoDetPlus, self).__init__()
        self.backbone = ShuffleNetV2()
        #self.fpn = GhostPAN()
        #self.head = NanoDetPlusHead()

    def forward(self, x):
        x = self.backbone(x)
        #x1,x2,x3,x4 = self.fpn(x1,x2,x3)
        #x = self.head(x1,x2,x3,x4)
        return x
