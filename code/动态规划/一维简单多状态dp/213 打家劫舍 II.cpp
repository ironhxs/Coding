// 213. 打家劫舍 II
// 关键点: 环形数组，分两种情况讨论：偷第一个和不偷第一个
// 易错点: 边界条件处理，当n>2时才需要考虑偷第一个的情况
// 日期: 2025.08.25

#include <vector>
#include <algorithm>
using namespace std;

//算法1: 分情况讨论 + 状态机DP
class Solution {
public:
    int rob2(vector<int>& nums,vector<int>::iterator begin,vector<int>::iterator end){
        int n = end - begin;
        vector<int> T(n + 1,0);  // T[i]表示偷第i个房子的最大收益
        vector<int> F(n + 1,0);  // F[i]表示不偷第i个房子的最大收益
        for(int i = 1;i <= n;i++){
            T[i] = *(begin + i - 1) + F[i - 1];  // 偷第i个房子
            F[i] = max(T[i - 1],F[i - 1]);       // 不偷第i个房子
        }
        return max(T[n],F[n]);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        //第一个不偷：考虑nums[1]到nums[n-1]
        int t1 = rob2(nums,nums.begin() + 1,nums.end());
        //偷第一个：考虑nums[2]到nums[n-2]，再加上nums[0]
        int t2 = n > 2?rob2(nums,nums.begin() + 2,nums.end() - 1) + nums[0]:nums[0];
        return max(t1,t2);
    }
};
