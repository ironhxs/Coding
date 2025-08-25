// 下降路径最小和
// 关键点: 二维DP，自顶向下，状态转移 dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]) + matrix[i-1][j-1]。
//       使用左右各一列哨兵避免边界特判；顶行基准仅对列 1..n 置 0，防止越界列被当作有效路径。
// 易错点: 1) 顶行 dp[0][0] 与 dp[0][n+1] 不能置 0，否则会把越界列当作 0 代价路径；
//         2) 返回答案应为最后一行列 1..n 的最小值，而不是 dp[m][n]。
// 日期: 2025.08.16

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        const int INF = INT_MAX / 4; // 防止后续加法溢出
        // dp 尺寸: (m+1) x (n+2)，左右各加一列哨兵
        vector<vector<int>> dp(m + 1, vector<int>(n + 2, INF));
        // 顶行基准：只能从 1..n 列起步
        for (int j = 1; j <= n; ++j) dp[0][j] = 0;
        // 转移
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int best = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1]));
                dp[i][j] = best + matrix[i - 1][j - 1];
            }
        }
        // 取最后一行 1..n 的最小值
        int ans = dp[m][1];
        for (int j = 2; j <= n; ++j) ans = min(ans, dp[m][j]);
        return ans;
    }
};

