// 53 最大子数组和
// 关键点: 建表：以i为结尾的最大子数组
// 易错点: 初始化dp为INT_MIN/2避免溢出
// 日期: 2025.08.30

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        //建表：以i为结尾的最大子数组
        vector<int> dp(n + 1,INT_MIN/2);
        
        for(int i = 1;i <= n;i++)
            dp[i] = max(dp[i - 1] + nums[i - 1],nums[i - 1]);
        return *max_element(dp.begin(),dp.end());
    }
};
