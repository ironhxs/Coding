// 第 N 个泰波那契数
// 关键点: 一维DP，泰波那契数列T(n) = T(n-1) + T(n-2) + T(n-3)
// 易错点: 边界条件处理，T(0)=0, T(1)=1, T(2)=1
// 日期: 2024.12.19

#include <vector>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n + 1,0);
        if(n < 2)
            return n;
        else if(n == 2)
            return 1;
        dp[1] = 1,dp[2] = 1;
        for(int i = 3;i <= n;i++){
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};
