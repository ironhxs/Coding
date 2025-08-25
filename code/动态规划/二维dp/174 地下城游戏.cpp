// 174 地下城游戏
// 关键点: 逆向动态规划，从右下角到左上角推导，避免正向DP的双变量问题
// 易错点: 需要保证生命值至少为1，边界条件设置
// 日期: 2025.08.21

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //如果从左往右，从上往下，因考虑两个变量的最值，比较难，所以逆过来
        int m = dungeon.size(),n = dungeon[0].size();
        //含义:从i,j到右下角所需的最小生命
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,INT_MAX));
        //从右下角到右下角应最少为1
        dp[m][n - 1] = dp[m - 1][n] =1;
        for(int i = m - 1;i >= 0;i--){
            for(int j = n - 1;j >= 0;j--){
                dp[i][j] = min(dp[i + 1][j],dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = max(dp[i][j],1);
            }
        }
        return dp[0][0];
    }
};
