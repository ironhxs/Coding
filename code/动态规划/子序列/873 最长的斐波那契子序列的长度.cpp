// 最长的斐波那契子序列的长度
// 关键点: 二维DP，固定后两个数，利用哈希表查找前驱
// 易错点: 需要判断diff <= arr[i]保证严格递增，返回值需要判断是否>=3
// 日期: 2025.09.05

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> hash;
        for(int i = 0;i < n;i++)
            hash[arr[i]] = i;
        
        int ret = 2;
        vector<vector<int>> dp(n,vector<int>(n,2));
        //定下后两个
        for(int j = 2;j < n;j++){
            for(int i = j - 1;i >= 1;i--){
                int diff = arr[j] - arr[i];
                if(diff <= arr[i] && hash.count(diff))
                    dp[i][j] = dp[hash[diff]][i] + 1;
                ret = max(ret,dp[i][j]);
            }
        }
        return ret==2?0:ret;
    }
};
