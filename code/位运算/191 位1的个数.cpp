// 位1的个数
// 关键点: 逐位检测，使用位运算测试每一位是否为1
// 易错点: 位移操作和位与操作的优先级
// 日期: 2025.08.06

#include <iostream>
using namespace std;

//算法1: 逐位检测法
class Solution {
public:
    int hammingWeight(int n) {
        int ret = 0;
        for(int i = 0;i < 32; i++){
            //依次测试这i位是否为1
            if(n & (1<<i))
                ret++;
        }
        return ret;
    }
};
