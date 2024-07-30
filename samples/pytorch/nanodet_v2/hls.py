import torch

from model import NanoDetPlus
# from preprocess import ShapeTransform, stack_batch_img, naive_collate, color_aug_and_norm, overlay_bbox_cv
# from new_postpro import post_process

from torch_mlir import torchscript



class_name=dict(classname=['person', 'bicycle', 'car', 'motorcycle', 'airplane', 'bus',
              'train', 'truck', 'boat', 'traffic_light', 'fire_hydrant',
              'stop_sign', 'parking_meter', 'bench', 'bird', 'cat', 'dog',
              'horse', 'sheep', 'cow', 'elephant', 'bear', 'zebra', 'giraffe',
              'backpack', 'umbrella', 'handbag', 'tie', 'suitcase', 'frisbee',
              'skis', 'snowboard', 'sports_ball', 'kite', 'baseball_bat',
              'baseball_glove', 'skateboard', 'surfboard', 'tennis_racket',
              'bottle', 'wine_glass', 'cup', 'fork', 'knife', 'spoon', 'bowl',
              'banana', 'apple', 'sandwich', 'orange', 'broccoli', 'carrot',
              'hot_dog', 'pizza', 'donut', 'cake', 'chair', 'couch',
              'potted_plant', 'bed', 'dining_table', 'toilet', 'tv', 'laptop',
              'mouse', 'remote', 'keyboard', 'cell_phone', 'microwave',
              'oven', 'toaster', 'sink', 'refrigerator', 'book', 'clock',
              'vase', 'scissors', 'teddy_bear', 'hair_drier', 'toothbrush'])


model=NanoDetPlus()
# 加载整个checkpoint而不仅仅是状态字典
#checkpoint = torch.load('model_320_1.0_withoutbn.pth', map_location=torch.device('cpu'))

# # 检查checkpoint的键
#print(checkpoint.keys())

# 如果状态字典被封装在'state_dict'键中
#model.load_state_dict(checkpoint['state_dict'],strict=False)

model_path = 'model_320_1.0_withoutbn.pth'
model_state_dict = torch.load(model_path, map_location=torch.device('cpu'))
model.load_state_dict(model_state_dict, strict=False)


module = torchscript.compile(model, torch.ones(
    1, 3, 320, 320), output_type="linalg-on-tensors")

print(module)