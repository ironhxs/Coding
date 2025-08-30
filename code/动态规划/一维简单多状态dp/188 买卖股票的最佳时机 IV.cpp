// 188 买卖股票的最佳时机 IV
// 关键点: k次交易的通用状态dp，使用2k个状态
// 易错点: 注意这个pow()返回值是double类型的
// 日期: 2025.08.30

#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
       int n = prices.size();
        vector<vector<int>> dp(2*k,vector<int>(n + 1,0));
        //初始化
        for(int i = 0;i < 2*k;i+=2)
            dp[i][0] = -prices[0];
        for(int i = 1;i <= n;i++){
            //first_buy
            dp[0][i] = max(dp[0][i - 1],-prices[i - 1]);
            for(int j = 1;j < 2*k;j++){
                //注意这个pow()返回值是double类型的
                dp[j][i] = max(dp[j][i - 1],dp[j - 1][i - 1] + (int)pow(-1,j+1) * prices[i - 1]);
            }
        }
        return dp[2*k - 1][n];
    }
};
