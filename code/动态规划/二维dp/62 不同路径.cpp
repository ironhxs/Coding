// 62 不同路径
// 关键点: 二维dp基础题，扩展dp表避免复杂初始化，dp[0][1] = 1技巧
// 易错点: 初始化dp[0][1] = 1，避免边界判断
// 日期: 2025.08.20

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        //建立dp表，注意这里拓展的技巧，避免复杂初始化
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        //初始化
        dp[0][1] = 1;
        //从左到右、从上到下填表
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        return dp[m][n];
    }
};
