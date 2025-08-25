// 740. 删除并获得点数
// 关键点: 转化为打家劫舍问题，先用hash统计每个数值的总和
// 易错点: 理解题意转化，相邻数值不能同时选择，类似打家劫舍的相邻房子
// 日期: 2025.08.25

#include <vector>
#include <algorithm>
using namespace std;

//算法1: 转化为打家劫舍问题
class Solution {
public:
    //神似打家劫舍,数值的'邻居'--->hash
    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin(),nums.end());
        vector<int> hash(n + 1,0);
        // 统计每个数值的总和
        for(auto e:nums)
            hash[e] +=e;
        
        //由此转化为hash的打家劫舍
        vector<int>T(n + 1,0);  // T[i]表示选择数值i的最大收益
        vector<int>F(n + 1,0);  // F[i]表示不选择数值i的最大收益
        for(int i = 1;i <= n;i++){
            T[i] = hash[i] + F[i - 1];      // 选择数值i，不能选择i-1
            F[i] = max(T[i - 1],F[i - 1]);  // 不选择数值i，可以选择或不选择i-1
        }
        return max(F[n],T[n]);
    }
};
