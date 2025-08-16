// 三步问题
// 关键点: 一维DP，每次可以走1、2或3步，类似斐波那契数列的扩展
// 易错点: 大数溢出问题，需要取模1000000007
// 日期: 2024.12.19

#include <vector>
using namespace std;

class Solution {
public:
    int waysToStep(int n) {
        //初始化
        if(n < 3)
            return n;
        else if(n == 3)
            return 4;
        //dp表：到第i个台阶的走法数
        vector<int>dp(n + 1);
        dp[1] = 1,dp[2] = 2,dp[3] = 4;
        for(int i = 4;i <= n;i++){
            //防止超int
            dp[i] = ((dp[i - 3] + dp[i - 2])%1000000007 + dp[i - 1])%1000000007;
        }
        return (dp[n]);
    }
};
