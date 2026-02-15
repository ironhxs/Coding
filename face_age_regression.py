#!/usr/bin/env python3
"""
人脸年龄回归模型 (Face Age Regression Model)
使用PyTorch实现基于卷积神经网络的人脸年龄预测模型

要求：
- 输入图片尺寸：64×64×3
- 使用Adam优化器
- 使用均方误差损失函数（MSE）
- 使用PIL进行图像预处理（不使用cv2）
- 严格按照指定的网络架构
"""

import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import Dataset, DataLoader
from PIL import Image
import os
import numpy as np


class FaceDataset(Dataset):
    """人脸数据集类，用于加载图像和对应的年龄标签"""
    
    def __init__(self, img_dir, label_file, transform=None):
        """
        初始化数据集
        
        Args:
            img_dir: 图像文件夹路径 (imgdata/)
            label_file: 标签文件路径 (label.txt)
            transform: 图像变换
        """
        self.img_dir = img_dir
        self.transform = transform
        self.data = []
        
        # 读取标签文件
        if os.path.exists(label_file):
            with open(label_file, 'r') as f:
                for line in f:
                    parts = line.strip().split()
                    if len(parts) >= 2:
                        img_name = parts[0]
                        age = float(parts[1])
                        self.data.append((img_name, age))
    
    def __len__(self):
        return len(self.data)
    
    def __getitem__(self, idx):
        img_name, age = self.data[idx]
        img_path = os.path.join(self.img_dir, img_name)
        
        # 使用PIL加载图像
        try:
            image = Image.open(img_path).convert('RGB')
            # 调整图像大小到64x64
            image = image.resize((64, 64), Image.LANCZOS)
            
            if self.transform:
                image = self.transform(image)
            else:
                # 默认变换：转换为tensor并归一化到[0,1]
                image = np.array(image, dtype=np.float32) / 255.0
                image = torch.from_numpy(image).permute(2, 0, 1)  # HWC -> CHW
                
        except Exception as e:
            print(f"Error loading image {img_path}: {e}")
            # 返回零图像和零年龄作为fallback
            image = torch.zeros(3, 64, 64)
            age = 0.0
        
        return image, torch.tensor(age, dtype=torch.float32)


class FaceAgeRegressionModel(nn.Module):
    """
    人脸年龄回归CNN模型
    
    网络架构：
    - 输入层：64×64×3
    - 卷积层1：8个3×3卷积核，步长1，无padding + ReLU + 2×2最大池化（步长2）
    - 卷积层2：16个3×3卷积核，步长1，无padding + ReLU + 2×2最大池化（步长2）  
    - 卷积层3：32个3×3卷积核，步长1，无padding + ReLU + 2×2最大池化（步长2）
    - 全连接层1：128个神经元 + ReLU
    - Dropout：激活概率0.5
    - 全连接层2：1个神经元 + ReLU
    """
    
    def __init__(self):
        super(FaceAgeRegressionModel, self).__init__()
        
        # 卷积层1：输入64x64x3 -> 输出62x62x8 -> 池化后31x31x8
        self.conv1 = nn.Conv2d(3, 8, kernel_size=3, stride=1, padding=0)
        self.relu1 = nn.ReLU()
        self.pool1 = nn.MaxPool2d(kernel_size=2, stride=2)
        
        # 卷积层2：输入31x31x8 -> 输出29x29x16 -> 池化后14x14x16  
        self.conv2 = nn.Conv2d(8, 16, kernel_size=3, stride=1, padding=0)
        self.relu2 = nn.ReLU()
        self.pool2 = nn.MaxPool2d(kernel_size=2, stride=2)
        
        # 卷积层3：输入14x14x16 -> 输出12x12x32 -> 池化后6x6x32
        self.conv3 = nn.Conv2d(16, 32, kernel_size=3, stride=1, padding=0)
        self.relu3 = nn.ReLU() 
        self.pool3 = nn.MaxPool2d(kernel_size=2, stride=2)
        
        # 计算展平后的特征维度：6x6x32 = 1152
        self.flatten = nn.Flatten()
        
        # 全连接层1：1152 -> 128
        self.fc1 = nn.Linear(6 * 6 * 32, 128)
        self.relu4 = nn.ReLU()
        
        # Dropout层：激活概率0.5（即丢弃概率0.5）
        self.dropout = nn.Dropout(0.5)
        
        # 全连接层2：128 -> 1 (年龄输出)
        self.fc2 = nn.Linear(128, 1)
        self.relu5 = nn.ReLU()
    
    def forward(self, x):
        # 卷积层1
        x = self.conv1(x)      # [batch, 3, 64, 64] -> [batch, 8, 62, 62]
        x = self.relu1(x)
        x = self.pool1(x)      # [batch, 8, 62, 62] -> [batch, 8, 31, 31]
        
        # 卷积层2  
        x = self.conv2(x)      # [batch, 8, 31, 31] -> [batch, 16, 29, 29]
        x = self.relu2(x)
        x = self.pool2(x)      # [batch, 16, 29, 29] -> [batch, 16, 14, 14]
        
        # 卷积层3
        x = self.conv3(x)      # [batch, 16, 14, 14] -> [batch, 32, 12, 12]
        x = self.relu3(x)
        x = self.pool3(x)      # [batch, 32, 12, 12] -> [batch, 32, 6, 6]
        
        # 展平
        x = self.flatten(x)    # [batch, 32, 6, 6] -> [batch, 1152]
        
        # 全连接层1
        x = self.fc1(x)        # [batch, 1152] -> [batch, 128]
        x = self.relu4(x)
        
        # Dropout
        x = self.dropout(x)
        
        # 全连接层2（输出层）
        x = self.fc2(x)        # [batch, 128] -> [batch, 1]
        x = self.relu5(x)
        
        return x


def train_face_age_model(model, train_loader, num_epochs=10, learning_rate=0.001):
    """
    训练人脸年龄回归模型
    
    Args:
        model: 模型实例
        train_loader: 训练数据加载器
        num_epochs: 训练轮数
        learning_rate: 学习率
    """
    # 使用Adam优化器
    optimizer = optim.Adam(model.parameters(), lr=learning_rate)
    
    # 使用均方误差损失函数（MSE）
    criterion = nn.MSELoss()
    
    # 设置设备
    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    model.to(device)
    
    print(f"Training on device: {device}")
    print(f"Model architecture:")
    print(model)
    print(f"\nStarting training for {num_epochs} epochs...")
    
    model.train()
    iteration = 0
    
    for epoch in range(num_epochs):
        epoch_loss = 0.0
        num_batches = 0
        
        for batch_idx, (images, ages) in enumerate(train_loader):
            images, ages = images.to(device), ages.to(device)
            
            # 前向传播
            optimizer.zero_grad()
            outputs = model(images)
            
            # 计算损失
            loss = criterion(outputs.squeeze(), ages)
            
            # 反向传播
            loss.backward()
            optimizer.step()
            
            # 输出每次迭代的损失值（按要求）
            iteration += 1
            print(f"Iteration {iteration}, Loss: {loss.item():.6f}")
            
            epoch_loss += loss.item()
            num_batches += 1
        
        avg_epoch_loss = epoch_loss / num_batches if num_batches > 0 else 0
        print(f"Epoch [{epoch+1}/{num_epochs}], Average Loss: {avg_epoch_loss:.6f}")
        print("-" * 50)


def main():
    """主函数"""
    print("=== 人脸年龄回归模型训练 ===")
    
    # 数据路径
    img_dir = "imgdata/"
    label_file = "label.txt"
    
    # 检查数据是否存在
    if not os.path.exists(img_dir):
        print(f"Warning: Image directory '{img_dir}' not found.")
        print("Creating dummy data for demonstration...")
        # 创建示例数据结构
        os.makedirs(img_dir, exist_ok=True)
        
        # 创建示例label.txt文件
        with open(label_file, 'w') as f:
            f.write("# 示例数据格式：\n")
            f.write("# image1.jpg 25\n")
            f.write("# image2.jpg 30\n")
            f.write("# image3.jpg 35\n")
        
        print(f"Please place your images in '{img_dir}' and update '{label_file}' with actual data.")
        print("Format: image_name age")
        return
    
    # 创建数据集和数据加载器
    dataset = FaceDataset(img_dir, label_file)
    
    if len(dataset) == 0:
        print(f"No valid data found in {label_file}. Please check your data.")
        return
    
    print(f"Found {len(dataset)} samples in dataset")
    
    # 创建数据加载器
    train_loader = DataLoader(dataset, batch_size=4, shuffle=True)
    
    # 创建模型
    model = FaceAgeRegressionModel()
    
    # 训练模型
    train_face_age_model(model, train_loader, num_epochs=5, learning_rate=0.001)
    
    print("\n=== 训练完成 ===")
    print("模型已训练完成。在实际使用中，您可以保存模型并用于预测。")


if __name__ == "__main__":
    main()