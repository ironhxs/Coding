// 只出现一次的数字
// 关键点: 利用异或运算的性质：a^a=0, a^0=a, 异或满足交换律和结合律
// 易错点: 理解异或的数学性质，初始值设为0
// 日期: 2025.08.06

#include <vector>
using namespace std;

//算法1: 异或运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //显然利用异或的运算性质
        //初始可以设为0，因为n^0=n
        int ret = 0;
        for(auto cur = nums.begin();cur < nums.end();cur++){
            ret^=*cur;
        }
        return ret;
    }
};

//算法2: 简化版异或 (range-based for)
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int num : nums){
            ret ^= num;
        }
        return ret;
    }
};

//算法3: STL accumulate版本
#include <numeric>
#include <functional>
class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};
