// 300 最长递增子序列
// 关键点: 经典LIS问题，dp[i]表示以i结尾的最长递增子序列长度
// 易错点: 双重循环，从j到i的状态转移
// 日期: 2025.08.31

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i = 0;i < n;i++){
            for(int j = i - 1;j >= 0;j--){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
