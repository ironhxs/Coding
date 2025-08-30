// 918 环形子数组的最大和
// 关键点: 环形想办法分类讨论转化为线形的
// 易错点: 子数组不能为空！！！
// 日期: 2025.08.30

#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    //环形想办法分类讨论转化为线形的
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        //转化为线形 最大子数组 和 最小子数组两个dp问题
        vector<int> _max(n + 1,INT_MIN/2);
        vector<int> _min(n + 1,INT_MAX/2);
        for(int i = 1;i <= n;i++){
            _max[i] = max(nums[i - 1],_max[i - 1] + nums[i - 1]);
            _min[i] = min(nums[i - 1],_min[i - 1] + nums[i - 1]);
        }
        int temp1 = *max_element(_max.begin(),_max.end());
        int temp2 = sum - *min_element(_min.begin(),_min.end());
        //子数组不能为空！！！
        temp2 = temp2?temp2:*max_element(nums.begin(),nums.end());
        return max(temp1,temp2);
    }
};
