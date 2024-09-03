import torch.nn as nn
import torch.nn.functional as F

from shufflenetv2 import ShuffleNetV2
from pan import GhostPAN
from pan import *
from head import NanoDetPlusHead
from head import *

class NanoDetPlus(nn.Module):
    def __init__(self):
        super(NanoDetPlus, self).__init__()
        self.backbone = ShuffleNetV2()
        self.fpn1 = GhostPAN1()
        self.fpn2 = GhostPAN2()
        self.fpn3 = GhostPAN3()
        self.fpn4 = GhostPAN4()
        # self.head = NanoDetPlusHead()
        self.head1 = NanoDetPlusHead1()
        self.head2 = NanoDetPlusHead2()
        self.head3 = NanoDetPlusHead3()
        self.head4 = NanoDetPlusHead4()
        

    def forward(self, x):
        x1, x2, x3 = self.backbone(x)
        f1 = self.fpn1(x1,x2,x3)
        y1 = self.head1(f1)
        f2 = self.fpn2(x1,x2,x3)
        y2 = self.head2(f2)
        f3 = self.fpn3(x1,x2,x3)
        y3 = self.head3(f3)
        f4 = self.fpn4(x1,x2,x3)
        y4 = self.head4(f4)
        outputs = torch.cat((y1,y2,y3,y4), dim=2).permute(0, 2, 1)
        return outputs