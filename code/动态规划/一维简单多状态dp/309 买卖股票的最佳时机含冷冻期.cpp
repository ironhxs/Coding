// 309 买卖股票的最佳时机含冷冻期
// 关键点: 三状态dp：持有、卖出、冷冻期
// 易错点: 冷冻期状态只能从卖出状态转移
// 日期: 2025.08.30

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(3,vector<int>(n + 1,0));
        dp[0][0] = -prices[0];
        for(int i = 1;i <= n;i++){
            dp[0][i] = max(dp[0][i - 1],dp[2][i-1] - prices[i - 1]);
            dp[1][i] = max(dp[1][i - 1],dp[0][i - 1] + prices[i - 1]);
            dp[2][i] = dp[1][i - 1];
        }
        return dp[1][n];
    }
};
