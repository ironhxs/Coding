// 只出现一次的数字 III
// 关键点: 先异或得到两个目标数的异或值，再用分组位进行分类异或
// 易错点: 处理INT_MIN的特殊情况，x&(-x)在边界值时的行为
// 日期: 2025.08.06

#include <vector>
#include <climits>
using namespace std;

//算法1: 异或分组法 (处理边界情况)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //异或的结果
        int _xor = 0;
        for(auto e:nums)
            _xor ^= e;
        // if()
        //取右边第一个不同的1，来分类
        //但是有特殊情况，取方法不适用于负边界
        int temp =(_xor==INT_MIN ? _xor:_xor&(-_xor));
        int ret1 = 0,ret2 = 0;
        for(auto e:nums)
            if(e & temp)
                ret1 ^= e;
            else
                ret2 ^= e;
        return {ret1,ret2};
    }
};

//算法2: 标准异或分组法
class Solution2 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        for(int num : nums) {
            xor_all ^= num;
        }
        
        // 找到任意一个为1的位作为分组依据
        int diff_bit = xor_all & (-xor_all);
        
        int num1 = 0, num2 = 0;
        for(int num : nums) {
            if(num & diff_bit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        
        return {num1, num2};
    }
};

//算法3: 使用其他位提取方法
class Solution3 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        for(int num : nums) {
            xor_all ^= num;
        }
        
        // 方法1: 找最右边的1
        // int diff_bit = xor_all & (-xor_all);
        
        // 方法2: 找任意一个1位 (避免溢出问题)
        int diff_bit = 1;
        while((xor_all & diff_bit) == 0) {
            diff_bit <<= 1;
        }
        
        int num1 = 0, num2 = 0;
        for(int num : nums) {
            if(num & diff_bit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        
        return {num1, num2};
    }
};

//算法4: 位运算优化版
class Solution4 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        for(int num : nums) {
            xor_all ^= num;
        }
        
        // 使用 __builtin_ctz 找到最右边的1的位置
        int rightmost_bit = 1 << __builtin_ctz(xor_all);
        
        int num1 = 0;
        for(int num : nums) {
            if(num & rightmost_bit) {
                num1 ^= num;
            }
        }
        
        return {num1, xor_all ^ num1};  // num2 = xor_all ^ num1
    }
};
