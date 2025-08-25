// 63 不同路径 II
// 关键点: 带障碍的路径计数，在基础路径上增加条件判断
// 易错点: 障碍物判断和dp值设置，初始化需要考虑第一个位置
// 日期: 2025.08.20

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //加了障碍就是加了个条件判断的过程，同上'不同路径'相似
        //建dp表
        vector<vector<int>>dp(obstacleGrid.size() + 1,vector<int>(obstacleGrid[0].size() + 1));
        //初始化
        dp[0][1] = obstacleGrid[0][0] == 0?1:0;
        //从左到右、从上到下填表
        for(int i = 1;i <= obstacleGrid.size();i++){
            for(int j = 1;j <= obstacleGrid[0].size();j++){
                if(obstacleGrid[i - 1][j - 1])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[obstacleGrid.size()][obstacleGrid[0].size()];
    }
};
