import torch

from test import NanoDetPlus
import torch_mlir


model=NanoDetPlus()
# 加载整个checkpoint而不仅仅是状态字典
#checkpoint = torch.load('model_320_1.0_withoutbn.pth', map_location=torch.device('cpu'))

# # 检查checkpoint的键
#print(checkpoint.keys())

# 如果状态字典被封装在'state_dict'键中
#model.load_state_dict(checkpoint['state_dict'],strict=False)

#model_path = 'model_320_allwithoutbn.pth'
#model_state_dict = torch.load(model_path, map_location=torch.device('cpu'))
# model.load_state_dict(model_state_dict, strict=False)

module = torch_mlir.compile(model, torch.ones(
    1, 192, 20, 20), output_type=torch_mlir.OutputType.LINALG_ON_TENSORS)

print(module)