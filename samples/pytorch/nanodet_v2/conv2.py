import torch.nn as nn

from activation import act_layers

class ConvModule(nn.Module):
    def __init__(
        self,
        in_channels,
        out_channels,
        kernel_size,
        stride=1,
        padding=0,
        dilation=1,
        groups=1,
        bias="auto",
        activation="ReLU",
        inplace=True,
    ):
        super(ConvModule, self).__init__()
        self.activation = activation
        self.inplace = inplace
        bias = False 

        # build convolution layer
        self.conv = nn.Conv2d(  #
            in_channels,
            out_channels,
            kernel_size,
            stride=stride,
            padding=padding,
            dilation=dilation,
            groups=groups,
            bias=bias,
        )

        self.bn = nn.BatchNorm2d(out_channels)

        # build activation layer
        if self.activation:
            self.act = act_layers(self.activation)


    def forward(self, x):
        x = self.conv(x)
        x = self.bn(x)
        x = self.act(x)
        return x
    

class DepthwiseConvModule(nn.Module):
    def __init__(
        self,
        in_channels,
        out_channels,
        kernel_size,
        stride=1,
        padding=0,
        dilation=1,
        bias="auto",
        activation="ReLU",
        inplace=True
    ):
        super(DepthwiseConvModule, self).__init__()
        self.activation = activation
        self.inplace = inplace
        # if the conv layer is before a norm layer, bias is unnecessary.
        bias = False

        # build convolution layer
        self.depthwise = nn.Conv2d(
            in_channels,
            in_channels,
            kernel_size,
            stride=stride,
            padding=padding,
            dilation=dilation,
            groups=in_channels,
            bias=bias,
        )
        self.pointwise = nn.Conv2d(
            in_channels, out_channels, kernel_size=1, stride=1, padding=0, bias=bias
        )

        self.dwnorm = nn.BatchNorm2d(in_channels)
        self.pwnorm = nn.BatchNorm2d(out_channels)
        
        # build activation layer
        if self.activation:
            self.act = act_layers(self.activation)
             
    def forward(self, x):
        x = self.depthwise(x)
        x = self.dwnorm(x)
        x = self.act(x)
        x = self.pointwise(x)
        x = self.pwnorm(x)
        x = self.act(x)
        return x