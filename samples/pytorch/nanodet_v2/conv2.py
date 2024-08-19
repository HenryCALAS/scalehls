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
    ):
        super(ConvModule, self).__init__()
        self.activation = activation
        bias = True

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

        self.act = act_layers(self.activation)


    def forward(self, x):
        x = self.conv(x)
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
    ):
        super(DepthwiseConvModule, self).__init__()
        self.activation = activation
        # if the conv layer is before a norm layer, bias is unnecessary.
        bias = True

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

        
        # build activation layer
        self.act = act_layers(self.activation)
             
    def forward(self, x):
        x = self.depthwise(x)
        x = self.act(x)
        x = self.pointwise(x)
        x = self.act(x)
        return x