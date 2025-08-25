// 198. 打家劫舍
// 关键点: 状态机DP，T[i]表示偷第i个房子，F[i]表示不偷第i个房子
// 易错点: 状态转移方程的理解，最后要比较T[n]和F[n]取最大值
// 日期: 2025.08.25

#include <vector>
#include <algorithm>
using namespace std;

//算法1: 状态机DP
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>T(n + 1,0);  // T[i]表示偷第i个房子的最大收益
        vector<int>F(n + 1,0);  // F[i]表示不偷第i个房子的最大收益
        for(int i = 1;i <= n;i++){
            T[i] = F[i - 1] + nums[i - 1];  // 偷第i个房子，前一个房子不能偷
            F[i] = max(F[i - 1],T[i - 1]);  // 不偷第i个房子，前一个房子可偷可不偷
        }
        return max(F[n],T[n]);
    }
};
