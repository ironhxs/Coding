#!/usr/bin/env python3
"""
交通场景多标签分类模型 (Traffic Scene Multi-label Classification Model)
使用PyTorch实现图片多标签分类功能

要求：
- 输入图片尺寸：64×64×3
- 使用Adam优化器
- 使用L1损失函数
- 输出层：7个神经元对应7个车型类别
- 使用训练集训练，测试集测试
- 输出每轮迭代的损失值
"""

import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import Dataset, DataLoader
from PIL import Image
import os
import numpy as np


class TrafficDataset(Dataset):
    """交通场景数据集类，用于加载图像和对应的多标签"""
    
    def __init__(self, label_file, transform=None):
        """
        初始化数据集
        
        Args:
            label_file: 标签文件路径 (trainlabels.txt 或 testlabels.txt)
            transform: 图像变换
        """
        self.transform = transform
        self.data = []
        
        # 读取标签文件
        if os.path.exists(label_file):
            with open(label_file, 'r') as f:
                for line in f:
                    parts = line.strip().split()
                    if len(parts) >= 8:  # 图片路径 + 7个标签
                        img_path = parts[0]
                        labels = [int(x) for x in parts[1:8]]  # 7个二进制标签
                        self.data.append((img_path, labels))
    
    def __len__(self):
        return len(self.data)
    
    def __getitem__(self, idx):
        img_path, labels = self.data[idx]
        
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
            # 返回零图像和零标签作为fallback
            image = torch.zeros(3, 64, 64)
            labels = [0] * 7
        
        return image, torch.tensor(labels, dtype=torch.float32)


class TrafficMultiLabelModel(nn.Module):
    """
    交通场景多标签分类CNN模型
    
    架构设计：
    - 输入层：64×64×3
    - 卷积特征提取层
    - 全连接分类层
    - 输出层：7个神经元对应7个车型类别
    """
    
    def __init__(self, num_classes=7):
        super(TrafficMultiLabelModel, self).__init__()
        
        # 卷积特征提取层
        self.features = nn.Sequential(
            # 第一个卷积块：64x64x3 -> 62x62x16 -> 31x31x16
            nn.Conv2d(3, 16, kernel_size=3, stride=1, padding=0),
            nn.ReLU(inplace=True),
            nn.MaxPool2d(kernel_size=2, stride=2),
            
            # 第二个卷积块：31x31x16 -> 29x29x32 -> 14x14x32
            nn.Conv2d(16, 32, kernel_size=3, stride=1, padding=0),
            nn.ReLU(inplace=True),
            nn.MaxPool2d(kernel_size=2, stride=2),
            
            # 第三个卷积块：14x14x32 -> 12x12x64 -> 6x6x64
            nn.Conv2d(32, 64, kernel_size=3, stride=1, padding=0),
            nn.ReLU(inplace=True),
            nn.MaxPool2d(kernel_size=2, stride=2),
        )
        
        # 计算展平后的特征维度：6x6x64 = 2304
        self.classifier = nn.Sequential(
            nn.Flatten(),
            nn.Linear(6 * 6 * 64, 256),
            nn.ReLU(inplace=True),
            nn.Dropout(0.5),
            nn.Linear(256, 128),
            nn.ReLU(inplace=True),
            nn.Dropout(0.3),
            nn.Linear(128, num_classes),  # 7个类别的输出
            nn.Sigmoid()  # 多标签分类使用Sigmoid激活
        )
    
    def forward(self, x):
        x = self.features(x)
        x = self.classifier(x)
        return x


def train_traffic_model(model, train_loader, test_loader=None, num_epochs=10, learning_rate=0.001):
    """
    训练交通场景多标签分类模型
    
    Args:
        model: 模型实例
        train_loader: 训练数据加载器
        test_loader: 测试数据加载器（可选）
        num_epochs: 训练轮数
        learning_rate: 学习率
    """
    # 使用Adam优化器
    optimizer = optim.Adam(model.parameters(), lr=learning_rate)
    
    # 使用L1损失函数（Mean Absolute Error）
    criterion = nn.L1Loss()
    
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
        
        for batch_idx, (images, labels) in enumerate(train_loader):
            images, labels = images.to(device), labels.to(device)
            
            # 前向传播
            optimizer.zero_grad()
            outputs = model(images)
            
            # 计算L1损失
            loss = criterion(outputs, labels)
            
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
        
        # 如果有测试集，进行测试
        if test_loader is not None:
            test_loss = evaluate_model(model, test_loader, criterion, device)
            print(f"Test Loss: {test_loss:.6f}")
        
        print("-" * 50)


def evaluate_model(model, test_loader, criterion, device):
    """
    评估模型在测试集上的性能
    
    Args:
        model: 模型实例
        test_loader: 测试数据加载器
        criterion: 损失函数
        device: 计算设备
    
    Returns:
        平均测试损失
    """
    model.eval()
    total_loss = 0.0
    num_batches = 0
    
    with torch.no_grad():
        for images, labels in test_loader:
            images, labels = images.to(device), labels.to(device)
            outputs = model(images)
            loss = criterion(outputs, labels)
            total_loss += loss.item()
            num_batches += 1
    
    model.train()
    return total_loss / num_batches if num_batches > 0 else 0


def create_dummy_data():
    """创建示例数据用于演示"""
    
    # 创建示例trainlabels.txt
    with open('trainlabels.txt', 'w') as f:
        f.write("# 示例训练数据格式：\n")
        f.write("# 图片路径 标签1 标签2 标签3 标签4 标签5 标签6 标签7\n")
        f.write("# train_img1.jpg 1 0 1 0 0 1 0\n")
        f.write("# train_img2.jpg 0 1 0 1 1 0 0\n")
    
    # 创建示例testlabels.txt
    with open('testlabels.txt', 'w') as f:
        f.write("# 示例测试数据格式：\n")
        f.write("# 图片路径 标签1 标签2 标签3 标签4 标签5 标签6 标签7\n")
        f.write("# test_img1.jpg 1 1 0 0 1 0 0\n")
        f.write("# test_img2.jpg 0 0 1 1 0 1 0\n")


def main():
    """主函数"""
    print("=== 交通场景多标签分类模型训练 ===")
    
    # 数据文件路径
    train_label_file = "trainlabels.txt"
    test_label_file = "testlabels.txt"
    
    # 检查数据是否存在
    if not os.path.exists(train_label_file) or not os.path.exists(test_label_file):
        print(f"Warning: Label files not found.")
        print("Creating dummy data files for demonstration...")
        create_dummy_data()
        print(f"Please update '{train_label_file}' and '{test_label_file}' with actual data.")
        print("Format: image_path label1 label2 label3 label4 label5 label6 label7")
        print("Each label should be 0 or 1 (binary labels for 7 vehicle categories)")
        return
    
    # 创建训练数据集和数据加载器
    train_dataset = TrafficDataset(train_label_file)
    
    if len(train_dataset) == 0:
        print(f"No valid training data found in {train_label_file}. Please check your data.")
        return
    
    print(f"Found {len(train_dataset)} training samples")
    train_loader = DataLoader(train_dataset, batch_size=4, shuffle=True)
    
    # 创建测试数据集和数据加载器（如果存在）
    test_loader = None
    test_dataset = TrafficDataset(test_label_file)
    if len(test_dataset) > 0:
        print(f"Found {len(test_dataset)} test samples")
        test_loader = DataLoader(test_dataset, batch_size=4, shuffle=False)
    else:
        print("No test data found, training without validation.")
    
    # 创建模型（7个车型类别）
    model = TrafficMultiLabelModel(num_classes=7)
    
    # 训练模型
    train_traffic_model(model, train_loader, test_loader, num_epochs=5, learning_rate=0.001)
    
    print("\n=== 训练完成 ===")
    print("模型已训练完成。在实际使用中，您可以保存模型并用于预测。")
    print("多标签分类输出说明：")
    print("- 输出值范围：[0, 1]（经过Sigmoid激活）")
    print("- 7个输出分别对应7个车型类别的概率")
    print("- 可以设置阈值（如0.5）来判断每个类别是否存在")


if __name__ == "__main__":
    main()