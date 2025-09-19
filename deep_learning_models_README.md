# 深度学习竞赛题目实现

本项目实现了两个深度学习竞赛题目的完整解决方案，使用PyTorch框架开发。

## 项目结构

```
.
├── face_age_regression.py              # 人脸年龄回归模型
├── traffic_multilabel_classification.py # 交通场景多标签分类模型
├── deep_learning_models_README.md      # 项目说明文档
├── imgdata/                            # 人脸图像数据目录
├── label.txt                          # 人脸年龄标签文件
├── trainlabels.txt                    # 交通场景训练标签
├── testlabels.txt                     # 交通场景测试标签
└── traffic*.jpg                       # 交通场景图像文件
```

## 任务一：人脸年龄回归模型（15分）

### 功能说明
使用卷积神经网络实现人脸年龄预测，输入人脸图像，输出预测年龄。

### 技术要求
- ✅ 输入图片尺寸：64×64×3
- ✅ 使用Adam优化器
- ✅ 使用均方误差损失函数（MSE）
- ✅ 使用PIL进行图像预处理（不使用cv2）
- ✅ 输出每次迭代的损失值

### 网络架构
严格按照要求实现的网络结构：

```
输入层：64×64×3
↓
卷积层1：8个3×3卷积核，步长1，无padding + ReLU + 2×2最大池化（步长2）
↓
卷积层2：16个3×3卷积核，步长1，无padding + ReLU + 2×2最大池化（步长2）
↓
卷积层3：32个3×3卷积核，步长1，无padding + ReLU + 2×2最大池化（步长2）
↓
全连接层1：128个神经元 + ReLU
↓
Dropout：激活概率0.5
↓
全连接层2：1个神经元 + ReLU（输出年龄）
```

### 数据格式
- **图片目录**: `imgdata/`
- **标签文件**: `label.txt`
- **格式**: `图片名 年龄`

### 使用方法
```bash
python3 face_age_regression.py
```

## 任务二：交通场景多标签分类模型（20分）

### 功能说明
实现图片多标签分类，识别交通场景中的7种不同车型类别。

### 技术要求
- ✅ 输入图片尺寸：64×64×3
- ✅ 使用Adam优化器
- ✅ 使用L1损失函数
- ✅ 输出层：7个神经元对应7个车型类别
- ✅ 使用训练集训练，测试集测试
- ✅ 输出每轮迭代的损失值

### 网络架构
设计的多标签分类网络结构：

```
输入层：64×64×3
↓
卷积特征提取层：
  - Conv2d(3→16, 3x3) + ReLU + MaxPool2d(2x2)
  - Conv2d(16→32, 3x3) + ReLU + MaxPool2d(2x2)
  - Conv2d(32→64, 3x3) + ReLU + MaxPool2d(2x2)
↓
全连接分类层：
  - Linear(2304→256) + ReLU + Dropout(0.5)
  - Linear(256→128) + ReLU + Dropout(0.3)
  - Linear(128→7) + Sigmoid
```

### 数据格式
- **训练标签**: `trainlabels.txt`
- **测试标签**: `testlabels.txt`
- **格式**: `图片路径 标签1 标签2 标签3 标签4 标签5 标签6 标签7`
  - 每个标签为0或1的二进制值，表示对应车型类别是否存在

### 使用方法
```bash
python3 traffic_multilabel_classification.py
```

## 环境要求

### 依赖安装
```bash
pip3 install torch torchvision pillow numpy
```

### Python版本
- Python 3.7+
- PyTorch 1.7+

## 运行示例

### 人脸年龄回归模型输出示例
```
=== 人脸年龄回归模型训练 ===
Found 3 samples in dataset
Training on device: cpu
Model architecture:
FaceAgeRegressionModel(...)

Starting training for 5 epochs...
Iteration 1, Loss: 1291.099976
Epoch [1/5], Average Loss: 1291.099976
--------------------------------------------------
Iteration 2, Loss: 1284.321289
Epoch [2/5], Average Loss: 1284.321289
--------------------------------------------------
...
=== 训练完成 ===
```

### 交通场景多标签分类模型输出示例
```
=== 交通场景多标签分类模型训练 ===
Found 2 training samples
Found 2 test samples
Training on device: cpu

Starting training for 5 epochs...
Iteration 1, Loss: 0.497548
Epoch [1/5], Average Loss: 0.497548
Test Loss: 0.495577
--------------------------------------------------
...
=== 训练完成 ===
```

## 实现特点

### 代码质量
- 完整的类和函数设计
- 详细的注释和文档字符串
- 错误处理和异常捕获
- 模块化的代码结构

### 功能完整性
- 数据加载和预处理
- 模型定义和训练
- 损失函数和优化器配置
- 训练过程监控和输出
- 测试集评估（多标签分类）

### 扩展性
- 支持GPU训练（自动检测设备）
- 可配置的训练参数
- 易于修改的网络架构
- 灵活的数据加载接口

## 注意事项

1. **数据准备**: 请确保按照指定格式准备训练数据
2. **路径设置**: 图像路径需要正确设置，建议使用绝对路径
3. **内存使用**: 根据可用内存调整batch_size参数
4. **训练时间**: 在CPU上训练可能较慢，建议使用GPU加速

## 开发者

本项目按照深度学习竞赛要求严格实现，确保网络架构、损失函数、优化器等完全符合题目规范。