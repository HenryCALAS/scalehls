import os
import cv2
import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F

from model import NanoDetPlus
from preprocess import ShapeTransform, stack_batch_img, naive_collate, color_aug_and_norm, overlay_bbox_cv
from new_postpro import post_process



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
checkpoint = torch.load('nanodet-plus-m_320.pth')

# 检查checkpoint的键
print(checkpoint.keys())

# 如果状态字典被封装在'state_dict'键中
model.load_state_dict(checkpoint['state_dict'])

os.environ["CUDA_DEVICE_ORDER"]="PCI_BUS_ID"
os.environ["CUDA_VISIBLE_DEVICES"]="0"

device = torch.device('cuda')

torch.backends.cudnn.enabled = True
torch.backends.cudnn.benchmark = True

img = '/content/000252.jpg'

img_info = {"id": 0}
if isinstance(img, str):
    img_info["file_name"] = os.path.basename(img)
    img = cv2.imread(img)
    if img is None:
        raise ValueError("Image not found or the image file is corrupted")
else:
    img_info["file_name"] = None

height, width = img.shape[:2]
img_info["height"] = height
img_info["width"] = width
meta = dict(img_info=img_info, raw_img=img, img=img)


#meta = Pipeline(None, meta, [320,320])

data_transform=ShapeTransform(keep_ratio=False)
meta = data_transform(meta, [320,320])
args=dict(brightness= 0.2, contrast= (0.6, 1.4), saturation= (0.5, 1.2),
normalize= [(103.53, 116.28, 123.675), (57.375, 57.12, 58.395)])
meta = color_aug_and_norm(meta, args)

meta["img"] = torch.from_numpy(meta["img"].transpose(2, 0, 1)).to(device)
meta = naive_collate([meta])
meta["img"] = stack_batch_img(meta["img"], divisible=32)

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
model = model.to(device)
meta["img"] = meta["img"].to(device)

model.eval()
preds = model(meta["img"])

res = post_process(preds, meta)
result = overlay_bbox_cv(meta['raw_img'][0], res[0], class_name['classname'], score_thresh=0.35)
