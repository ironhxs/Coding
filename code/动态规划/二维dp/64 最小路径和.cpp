// 64 最小路径和
// 关键点: 路径最小值问题，同珠宝问题，变成最小值
// 易错点: 需要初始化额外行列为INT_MAX，dp[0][1] = dp[1][0] = 0
// 日期: 2025.08.20

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //同'珠宝'，不过变成最小值了
        int m = grid.size(),n = grid[0].size();
        //建表
        //需要初始化额外的那两列，全部初始化为INT_MAX
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,INT_MAX));
        dp[0][1] = 0,dp[1][0] = 0;
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++)
                dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + grid[i - 1][j - 1];
        }
        return dp[m][n];
    }
};
