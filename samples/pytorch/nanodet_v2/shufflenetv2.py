import torch
import torch.nn as nn
from activation import act_layers

class ShuffleV2Block2(nn.Module):
    def __init__(self, inp, oup, stride, activation="ReLU"):
        super(ShuffleV2Block2, self).__init__()
        self.stride = stride

        branch_features = oup // 2
        if self.stride > 1:
            self.branch1 = nn.Sequential(
                self.depthwise_conv(
                    inp, inp, kernel_size=3, stride=self.stride, padding=1
                ),
                nn.BatchNorm2d(inp),
                nn.Conv2d(
                    inp, branch_features, kernel_size=1, stride=1, padding=0, bias=False
                ),
                nn.BatchNorm2d(branch_features),
                act_layers(activation),
            )
        else:
            self.branch1 = nn.Sequential()

        self.branch2 = nn.Sequential(
            nn.Conv2d(
                inp if (self.stride > 1) else branch_features,
                branch_features,
                kernel_size=1,
                stride=1,
                padding=0,
                bias=False,
            ),
            nn.BatchNorm2d(branch_features),
            act_layers(activation),
            self.depthwise_conv(
                branch_features,
                branch_features,
                kernel_size=3,
                stride=self.stride,
                padding=1,
            ),
            nn.BatchNorm2d(branch_features),
            nn.Conv2d(
                branch_features,
                branch_features,
                kernel_size=1,
                stride=1,
                padding=0,
                bias=False,
            ),
            nn.BatchNorm2d(branch_features),
            act_layers(activation),
        )

    @staticmethod
    def depthwise_conv(i, o, kernel_size, stride=1, padding=0, bias=False):
        return nn.Conv2d(i, o, kernel_size, stride, padding, bias=bias, groups=i)

    def forward(self, x):
        print(self.stride, x.shape)
        if self.stride == 1:
            x1, x2 = x.chunk(2, dim=1)
            out = torch.cat((x1, self.branch2(x2)), dim=1)
        else:
            out = torch.cat((self.branch1(x), self.branch2(x)), dim=1)
        print(out.shape)
        out = out.view(1, 2, 58, 40, 40)
        out = torch.transpose(out, 1, 2).contiguous()
        out = out.view(1, -1, 40, 40)
        print(out.shape)
        return out
    
class ShuffleV2Block3(nn.Module):
    def __init__(self, inp, oup, stride, activation="ReLU"):
        super(ShuffleV2Block3, self).__init__()
        self.stride = stride

        branch_features = oup // 2

        if self.stride > 1:
            self.branch1 = nn.Sequential(
                self.depthwise_conv(
                    inp, inp, kernel_size=3, stride=self.stride, padding=1
                ),
                nn.BatchNorm2d(inp),
                nn.Conv2d(
                    inp, branch_features, kernel_size=1, stride=1, padding=0, bias=False
                ),
                nn.BatchNorm2d(branch_features),
                act_layers(activation),
            )
        else:
            self.branch1 = nn.Sequential()

        self.branch2 = nn.Sequential(
            nn.Conv2d(
                inp if (self.stride > 1) else branch_features,
                branch_features,
                kernel_size=1,
                stride=1,
                padding=0,
                bias=False,
            ),
            nn.BatchNorm2d(branch_features),
            act_layers(activation),
            self.depthwise_conv(
                branch_features,
                branch_features,
                kernel_size=3,
                stride=self.stride,
                padding=1,
            ),
            nn.BatchNorm2d(branch_features),
            nn.Conv2d(
                branch_features,
                branch_features,
                kernel_size=1,
                stride=1,
                padding=0,
                bias=False,
            ),
            nn.BatchNorm2d(branch_features),
            act_layers(activation),
        )

    @staticmethod
    def depthwise_conv(i, o, kernel_size, stride=1, padding=0, bias=False):
        return nn.Conv2d(i, o, kernel_size, stride, padding, bias=bias, groups=i)

    def forward(self, x):
        if self.stride == 1:
            x1, x2 = x.chunk(2, dim=1)
            out = torch.cat((x1, self.branch2(x2)), dim=1)
        else:
            out = torch.cat((self.branch1(x), self.branch2(x)), dim=1)

        out = out.view(1, 2, 116, 20, 20)
        out = torch.transpose(out, 1, 2).contiguous()
        out = out.view(1, -1, 20, 20)
        
        return out

class ShuffleV2Block4(nn.Module):
    def __init__(self, inp, oup, stride, activation="ReLU"):
        super(ShuffleV2Block4, self).__init__()
        self.stride = stride

        branch_features = oup // 2

        if self.stride > 1:
            self.branch1 = nn.Sequential(
                self.depthwise_conv(
                    inp, inp, kernel_size=3, stride=self.stride, padding=1
                ),
                nn.BatchNorm2d(inp),
                nn.Conv2d(
                    inp, branch_features, kernel_size=1, stride=1, padding=0, bias=False
                ),
                nn.BatchNorm2d(branch_features),
                act_layers(activation),
            )
        else:
            self.branch1 = nn.Sequential()

        self.branch2 = nn.Sequential(
            nn.Conv2d(
                inp if (self.stride > 1) else branch_features,
                branch_features,
                kernel_size=1,
                stride=1,
                padding=0,
                bias=False,
            ),
            nn.BatchNorm2d(branch_features),
            act_layers(activation),
            self.depthwise_conv(
                branch_features,
                branch_features,
                kernel_size=3,
                stride=self.stride,
                padding=1,
            ),
            nn.BatchNorm2d(branch_features),
            nn.Conv2d(
                branch_features,
                branch_features,
                kernel_size=1,
                stride=1,
                padding=0,
                bias=False,
            ),
            nn.BatchNorm2d(branch_features),
            act_layers(activation),
        )

    @staticmethod
    def depthwise_conv(i, o, kernel_size, stride=1, padding=0, bias=False):
        return nn.Conv2d(i, o, kernel_size, stride, padding, bias=bias, groups=i)

    def forward(self, x):
        if self.stride == 1:
            x1, x2 = x.chunk(2, dim=1)
            out = torch.cat((x1, self.branch2(x2)), dim=1)
        else:
            out = torch.cat((self.branch1(x), self.branch2(x)), dim=1)

        out = out.view(1, 2, 232, 10, 10)
        out = torch.transpose(out, 1, 2).contiguous()
        out = out.view(1, -1, 10, 10)
        
        return out

class ShuffleNetV2(nn.Module):
    def __init__(
        self,
        model_size="1.0x",
        out_stages=(2, 3, 4),
        with_last_conv=False,
        kernal_size=3,
        activation="LeakyReLU"
    ):
        super(ShuffleNetV2, self).__init__()
        self.stage_repeats = [4, 8, 4]
        self.model_size = model_size
        self.out_stages = out_stages
        self.with_last_conv = with_last_conv
        self.kernal_size = kernal_size
        self.activation = activation
        self._stage_out_channels = [24, 116, 232, 464, 1024]


        # building first layer
        input_channels = 3
        output_channels = self._stage_out_channels[0]
        self.conv1 = nn.Sequential(
            nn.Conv2d(input_channels, output_channels, 3, 2, 1, bias=False),
            nn.BatchNorm2d(output_channels),
            act_layers(activation),
        )
        input_channels = output_channels

        self.maxpool = nn.MaxPool2d(kernel_size=3, stride=2, padding=1)

        output_channels = 116
        self.stage2 = nn.Sequential(
            ShuffleV2Block2(
                    input_channels, output_channels, 2, activation=activation
            ),
            ShuffleV2Block2(
                    output_channels, output_channels, 1, activation=activation
            ),
            ShuffleV2Block2(
                    output_channels, output_channels, 1, activation=activation
            ),
            ShuffleV2Block2(
                    output_channels, output_channels, 1, activation=activation
            )
        )
        input_channels = output_channels

        output_channels = 232
        self.stage3 = nn.Sequential(
            ShuffleV2Block3(
                    input_channels, output_channels, 2, activation=activation
            ),
            ShuffleV2Block3(
                    output_channels, output_channels, 1, activation=activation
            ),
            ShuffleV2Block3(
                    output_channels, output_channels, 1, activation=activation
            ),
            ShuffleV2Block3(
                    output_channels, output_channels, 1, activation=activation
            ),
            ShuffleV2Block3(
                    output_channels, output_channels, 1, activation=activation
            ),
            ShuffleV2Block3(
                    output_channels, output_channels, 1, activation=activation
            ),
            ShuffleV2Block3(
                    output_channels, output_channels, 1, activation=activation
            ),
            ShuffleV2Block3(
                    output_channels, output_channels, 1, activation=activation
            )
        )
        input_channels = output_channels

        output_channels = 464
        self.stage4 = nn.Sequential(
            ShuffleV2Block4(
                    input_channels, output_channels, 2, activation=activation
            ),
            ShuffleV2Block4(
                    output_channels, output_channels, 1, activation=activation
            ),
            ShuffleV2Block4(
                    output_channels, output_channels, 1, activation=activation
            ),
            ShuffleV2Block4(
                    output_channels, output_channels, 1, activation=activation
            )
        )
        input_channels = output_channels
        output_channels = self._stage_out_channels[-1]

    def forward(self, x):
        x = self.conv1(x)
        x = self.maxpool(x)
        output = []

        x = self.stage2(x)
        output.append(x)

        x = self.stage3(x)
        output.append(x)

        x = self.stage4(x)
        output.append(x)

        return output