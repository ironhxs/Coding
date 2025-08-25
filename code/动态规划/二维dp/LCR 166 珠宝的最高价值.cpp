// LCR 166 珠宝的最高价值
// 关键点: 路径最大值问题，满足单调性，走过的dp值不会变
// 易错点: 取最大值而不是求和，dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + frame[i-1][j-1]
// 日期: 2025.08.20

#include <vector>
using namespace std;

class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        //这是在不同路径基础上加了最值问题
        //但是可以发现比较简单的点在于满足单调性，即走过的dp值不会变了
        int m = frame.size(),n = frame[0].size();
        vector<vector<int>> dp (m + 1,vector<int>(n + 1,0));
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++)
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]) + frame[i - 1][j - 1];
        }
        return dp[m][n];
    }
};
