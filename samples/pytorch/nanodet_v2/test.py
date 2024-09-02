import torch.nn as nn
import torch

from pan import GhostModule

class NanoDetPlus(nn.Module):
    def __init__(self):
        super(NanoDetPlus, self).__init__()
        self.fpn = GhostModule(inp=192,oup=96)

    def forward(self, x):
        out = self.fpn(x)
        return out
