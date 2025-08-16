// 使用最小花费爬楼梯
// 关键点: 一维DP，可以从第0或第1个台阶开始，每次可以爬1或2个台阶
// 易错点: 理解题意，cost[i]是离开第i个台阶的花费
// 日期: 2024.12.19

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1,0);
        for(int i = 2;i <= cost.size();i++){
            dp[i] = min(dp[i - 1] + cost[i - 1],dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }
};
