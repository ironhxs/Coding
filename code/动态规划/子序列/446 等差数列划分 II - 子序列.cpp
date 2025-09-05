// 等差数列划分 II - 子序列
// 关键点: 二维DP计数，dp[i][j]表示以i,j结尾的等差数列个数，long避免溢出
// 易错点: 计算前驱时2*nums[i]可能超int，需要强制转换为long
// 日期: 2025.09.05

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //建立数值和索引的映射
        //求前一个数(long temp = 2 * nums[i] - nums[j])时会超int
        unordered_map<long,vector<int>> hash;
        hash[nums[0]].emplace_back(0);
        int ret = 0;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 1;i < n;i++){
            for(int j = i + 1;j < n;j++){
                long temp = 2 * (long)nums[i] - nums[j];
                if(hash.count(temp)){
                    for(auto e : hash[temp])
                        //重点理解这里！！！
                        dp[i][j] += dp[e][i] + 1;
                }
                ret += dp[i][j];
            }
            //只有倒数第二个遍历过了，再建立这个索引，以便保持相对顺序
            hash[nums[i]].emplace_back(i);
        }
        return ret;
    }
};
