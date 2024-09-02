import torch
import torch.nn as nn
import math
from activation import act_layers
from conv2 import ConvModule, DepthwiseConvModule

def bilinear_upsample20(input_tensor):
    output_tensor = torch.ones((1, 96, 20, 20))
    #for i in range(30):
    #    output_tensor[0,i,0,0]=input_tensor[0,i,1,1]

    return output_tensor

def bilinear_upsample40(input_tensor):
    output_tensor = torch.ones((1, 96, 40, 40))
    #for i in range(30):
    #    output_tensor[0,i,0,0]=input_tensor[0,i,1,1]

    return output_tensor

class GhostModule(nn.Module):
    def __init__(
        self, inp, oup, kernel_size=1, ratio=2, dw_size=3, stride=1, activation="LeakyReLU"
    ):
        super(GhostModule, self).__init__()
        self.oup = oup
        init_channels = math.ceil(oup / ratio)
        new_channels = init_channels * (ratio - 1)

        self.primary_conv = nn.Sequential(
            nn.Conv2d(
                inp, init_channels, kernel_size, stride, kernel_size // 2, bias=True
            ),
            act_layers(activation),
        )

        self.cheap_operation = nn.Sequential(
            nn.Conv2d(
                init_channels,
                new_channels,
                dw_size,
                1,
                dw_size // 2,
                groups=init_channels,
                bias=True,
            ),
            act_layers(activation),
        )

    def forward(self, x):
        x1 = self.primary_conv(x)
        x2 = self.cheap_operation(x1)
        out = torch.cat((x1, x2), dim=1)
        return out


class GhostBottleneck(nn.Module):
    """Ghost bottleneck w/ optional SE"""

    def __init__(
        self,
        in_chs,
        mid_chs,
        out_chs,
        dw_kernel_size=3,
        stride=1,
        activation="ReLU",
    ):
        super(GhostBottleneck, self).__init__()
        self.stride = stride

        # Point-wise expansion
        self.ghost1 = GhostModule(in_chs, mid_chs, activation=activation)

        # Point-wise linear projection
        self.ghost2 = GhostModule(mid_chs, out_chs, activation=None)

        # shortcut
        self.shortcut = nn.Sequential(
            nn.Conv2d(
                in_chs,
                in_chs,
                dw_kernel_size,
                stride=stride,
                padding=(dw_kernel_size - 1) // 2,
                groups=in_chs,
                bias=True,
            ),
            nn.Conv2d(in_chs, out_chs, 1, stride=1, padding=0, bias=True),
        )

    def forward(self, x):
        residual = x

        # 1st ghost bottleneck
        x = self.ghost1(x)

        # 2nd ghost bottleneck
        x = self.ghost2(x)

        x += self.shortcut(residual)
        return x



class GhostBlocks(nn.Module):

    def __init__(
        self,
        in_channels,
        out_channels,
        expand=1,
        kernel_size=5,
        activation="LeakyReLU",
    ):
        super(GhostBlocks, self).__init__()

        self.blocks = nn.Sequential(
            GhostBottleneck(
                in_channels,
                out_channels,
                out_channels,
                dw_kernel_size=kernel_size,
                activation=activation,
            )
        )

    def forward(self, x):
        out = self.blocks(x)
        return out


class GhostPAN(nn.Module):

    def __init__(
        self,
        in_channels=[116, 232, 464],
        out_channels=96,
        #手动输入的
        kernel_size=5,
        expand=1,
        num_extra_level=1,
        #upsample_cfg=dict(scale_factor=2, mode="bilinear"),
        activation="LeakyReLU",
    ):
        super(GhostPAN, self).__init__()
        self.in_channels = in_channels
        self.out_channels = out_channels

        conv = DepthwiseConvModule

        # build top-down blocks
        self.upsample20 = bilinear_upsample20
        self.upsample40 = bilinear_upsample40
        self.reduce_layers = nn.ModuleList()
        for idx in range(len(in_channels)):
            self.reduce_layers.append(
                ConvModule(
                    in_channels[idx],
                    out_channels,
                    1,
                    activation=activation,
                )
            )
            
        self.top_down_blocks = nn.ModuleList()
        for idx in range(2, 0, -1):
            self.top_down_blocks.append(
                GhostBlocks(
                    out_channels * 2,
                    out_channels,
                    expand,
                    kernel_size=kernel_size,
                    activation=activation,
                )
            )

        # build bottom-up blocks
        self.downsamples = nn.ModuleList()
        self.bottom_up_blocks = nn.ModuleList()
        for idx in range(len(in_channels) - 1):
            self.downsamples.append(
                conv(
                    out_channels,
                    out_channels,
                    kernel_size,
                    stride=2,
                    padding=kernel_size // 2,
                    activation=activation,
                )
            )
            self.bottom_up_blocks.append(
                GhostBlocks(
                    out_channels * 2,
                    out_channels,
                    expand,
                    kernel_size=kernel_size,
                    activation=activation,
                )
            )
    

        # extra layers
        self.extra_lvl_in_conv = nn.ModuleList()
        self.extra_lvl_out_conv = nn.ModuleList()
        for i in range(num_extra_level):
            self.extra_lvl_in_conv.append(
                conv(
                    out_channels,
                    out_channels,
                    kernel_size,
                    stride=2,
                    padding=kernel_size // 2,
                    activation=activation,
                )
            )
            self.extra_lvl_out_conv.append(
                conv(
                    out_channels,
                    out_channels,
                    kernel_size,
                    stride=2,
                    padding=kernel_size // 2,
                    activation=activation,
                )
            )

    def forward(self, x1, x2, x3):
        x1 = self.reduce_layers[0](x1)
        x2 = self.reduce_layers[1](x2)
        x3 = self.reduce_layers[2](x3)
        return x1, x1, x2, x3
        feat_heigh = x3
        feat_low = x2

        upsample_feat = self.upsample20(feat_heigh)
   
        inner_out1 = self.top_down_blocks[0](
                 torch.cat([upsample_feat, feat_low], 1)
            )
             
        feat_heigh = inner_out1
        feat_low = x1
        upsample_feat = self.upsample40(feat_heigh)
        inner_out2 = self.top_down_blocks[1](
                 torch.cat([upsample_feat, feat_low], 1)
            )

        out0 = inner_out2
        feat_low = out0
        feat_heigh = inner_out1
        downsample_feat = self.downsamples[0](feat_low)
        out1 = self.bottom_up_blocks[0](
                torch.cat([downsample_feat, feat_heigh], 1)
            )

        feat_low = out1
        feat_heigh = x3
        downsample_feat = self.downsamples[1](feat_low)
        out2 = self.bottom_up_blocks[1](
                torch.cat([downsample_feat, feat_heigh], 1)
            )

        # extra layers
        for extra_in_layer, extra_out_layer in zip(
            self.extra_lvl_in_conv, self.extra_lvl_out_conv
        ):
            out3=(extra_in_layer(x3) + extra_out_layer(out2))

        return out0, out1, out2, out3