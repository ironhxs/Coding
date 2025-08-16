// 两整数之和
// 关键点: 模拟底层电路，异或计算不进位和，与运算计算进位，循环直到无进位
// 易错点: 理解进位的计算和传递，注意左移操作的位置
// 日期: 2025.08.06

#include <iostream>
using namespace std;

//算法1: 模拟电路加法器
class Solution {
public:
    int getSum(int a, int b) {
        //模拟底层电路实现
        //不进位之和
        while(b){
            int temp = a;
            a ^= b;
            //未处理的进位之和
            b &=  temp ;
            // b << 1;
            b = b << 1;
        }
        return a;
    }
};

//算法2: 递归版本
class Solution2 {
public:
    int getSum(int a, int b) {
        if(b == 0) return a;
        
        int sum = a ^ b;        // 不进位的和
        int carry = (a & b) << 1; // 进位
        
        return getSum(sum, carry);
    }
};

//算法3: 优化的迭代版本
class Solution3 {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            int carry = (a & b) << 1;  // 计算进位
            a = a ^ b;                 // 计算不进位的和
            b = carry;                 // 更新进位
        }
        return a;
    }
};

//算法4: 处理负数的版本 (Java风格转C++)
class Solution4 {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            int carry = (unsigned int)(a & b) << 1;  // 无符号右移避免符号位问题
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
