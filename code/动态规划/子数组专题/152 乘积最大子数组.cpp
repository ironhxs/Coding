// 152 乘积最大子数组
// 关键点: 维护最大值和最小值两个状态，处理负数情况
// 易错点: 负数会让最大值变最小值，最小值变最大值
// 日期: 2025.08.30

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> _max(n + 1,1);
        vector<int> _min(n + 1,1);
        for(int i = 1;i <= n;i++){
            _max[i] = max(_min[i - 1] * nums[i - 1],max(nums[i - 1],_max[i - 1] * nums[i - 1]));
            _min[i] = min(_max[i - 1] * nums[i - 1],min(nums[i - 1],_min[i - 1] * nums[i - 1]));
        }
        return *max_element(_max.begin() + 1,_max.end());
    }
};
