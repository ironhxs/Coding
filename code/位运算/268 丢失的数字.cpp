// 丢失的数字
// 关键点: 利用异或性质，将数组元素与完整序列[0,n]异或，相同数字抵消，剩下缺失数字
// 易错点: 理解异或抵消原理，注意循环范围是1到nums.size()
// 日期: 2025.08.06

#include <vector>
#include <numeric>
using namespace std;

//算法1: 异或运算
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //还是利用异或的性质
        int ret = 0;
        for(auto e:nums)
            ret ^= e;
        for(int i=1;i <= nums.size();i++)
            ret ^= i;
        return ret;
    }
};

//算法2: 优化的异或 (一次遍历)
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int ret = nums.size();  // 先异或n
        for(int i = 0; i < nums.size(); i++) {
            ret ^= i ^ nums[i];  // 同时异或索引和元素
        }
        return ret;
    }
};

//算法3: 数学公式 (等差数列求和)
class Solution3 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;  // 0+1+2+...+n的和
        int actualSum = accumulate(nums.begin(), nums.end(), 0);
        return expectedSum - actualSum;
    }
};

//算法4: 位运算+索引技巧
class Solution4 {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < nums.size(); i++) {
            ret ^= (i + 1) ^ nums[i];  // (i+1)对应完整序列
        }
        return ret;
    }
};
