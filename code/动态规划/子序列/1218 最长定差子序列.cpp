// 最长定差子序列
// 关键点: 哈希表优化DP，利用定差特性直接查找前驱
// 易错点: O(n^2)会超时，需要用哈希表将查找前驱优化到O(1)
// 日期: 2025.09.05

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        // vector<int> dp(n + 1,1);
        //数据量太大了O（n^2）会超时
        // for(int i = 1;i < n;i++){
        //     for(int j = i - 1;j >= 0;j--){
        //         if(arr[i] - arr[j] == difference){
        //             dp[i] = max(dp[i],dp[j] + 1);
        //         }
        //     }
        // }
        // return *max_element(dp.begin(),dp.end());
        
        //因为是定长间距可以考虑哈希表
        unordered_map<int,int> hash_dp;
        int ret = 1;
        for(auto e:arr){
            //同时初始化了
            hash_dp[e] = hash_dp[e - difference] + 1;
             ret = max(ret,hash_dp[e]);
        }
        return ret;
    }
};
