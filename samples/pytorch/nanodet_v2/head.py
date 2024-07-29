import torch
import torch.nn as nn

from conv2 import ConvModule, DepthwiseConvModule
    
class NanoDetPlusHead(nn.Module):

    def __init__(
        self,
        num_classes=80,
        input_channel=96,
        feat_channels=96,
        stacked_convs=2,
        kernel_size=5,
        strides=[8, 16, 32, 64],
        conv_type="DWConv",
        norm_cfg=dict(type="BN"),
        reg_max=7,
        activation="LeakyReLU"
    ):
        super(NanoDetPlusHead, self).__init__()
        self.num_classes = num_classes
        self.in_channels = input_channel
        self.feat_channels = feat_channels
        self.stacked_convs = stacked_convs
        self.kernel_size = kernel_size
        self.strides = strides
        self.reg_max = reg_max
        self.activation = activation
        self.ConvModule = ConvModule if conv_type == "Conv" else DepthwiseConvModule
        self.norm_cfg = norm_cfg
        self._init_layers()
        #self.init_weights()

    def _init_layers(self):
        self.cls_convs = nn.ModuleList()
        for _ in self.strides:
            cls_convs = self._buid_not_shared_head()
            self.cls_convs.append(cls_convs)

        self.gfl_cls = nn.ModuleList(
            [
                nn.Conv2d(
                    self.feat_channels,
                    self.num_classes + 4 * (self.reg_max + 1),
                    1,
                    padding=0,
                )
                for _ in self.strides
            ]
        )

    def _buid_not_shared_head(self):
        cls_convs = nn.ModuleList()
        for i in range(self.stacked_convs):
            chn = self.in_channels if i == 0 else self.feat_channels
            cls_convs.append(
                self.ConvModule(
                    chn,
                    self.feat_channels,
                    self.kernel_size,
                    stride=1,
                    padding=self.kernel_size // 2,
                    activation=self.activation,
                )
            )
        return cls_convs
    
    def forward(self, x1, x2, x3, x4):
        outputs = []
        feat = x1
        for conv in self.cls_convs[0]:
            feat = conv(feat)
        output = self.gfl_cls[0](feat)
        outputs.append(output.flatten(start_dim=2))
        feat = x2
        for conv in self.cls_convs[1]:
            feat = conv(feat)
        output = self.gfl_cls[1](feat)
        outputs.append(output.flatten(start_dim=2))
        feat = x3
        for conv in self.cls_convs[2]:
            feat = conv(feat)
        output = self.gfl_cls[2](feat)
        outputs.append(output.flatten(start_dim=2))
        feat = x4
        for conv in self.cls_convs[3]:
            feat = conv(feat)
        output = self.gfl_cls[3](feat)
        outputs.append(output.flatten(start_dim=2))
        outputs = torch.cat(outputs, dim=2).permute(0, 2, 1)
        return outputs