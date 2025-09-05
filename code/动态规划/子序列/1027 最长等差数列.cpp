// 最长等差数列
// 关键点: 二维DP，固定倒数第二个和最后一个数，哈希表查找前驱
// 易错点: 需要在遍历完i位置后再将i加入哈希表，保证下标顺序
// 日期: 2025.09.05

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,2));
        unordered_map<int,int> hash;
        
        //与上个最长斐波那契不同在于那是严格递增的所以找到符合条件的一定是在前面的
        hash[nums[0]] = 0;
        int ret = 2;
        // 先固定倒数第二个数，再枚举最后一个数（可以等i位置填完后再将i的位置丢进哈希表，这样可以保证哈希表内的元素的下标必然是小的，就可以不需要判断b<a<c的情况）
        for(int i = 1;i < n;i++){
            for(int j = i + 1;j < n;j++){
                int temp = 2 * nums[i] - nums[j];
                if(hash.count(temp))
                    dp[i][j] = dp[hash[temp]][i] + 1;
                ret = max(ret,dp[i][j]);
            }
            hash[nums[i]] = i;
        }
        return ret;
    }
};
