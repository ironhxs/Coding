// 376 摆动序列
// 关键点: 摆动序列要求相邻元素差值正负交替，需要维护符号状态
// 易错点: 隐形bug：此时dp[i]已经更新了，不能再判断了！！！
// 日期: 2025.08.31

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> sym(n,0);
        if(n < 2)
            return n;
        for(int i = 1;i < n;i++){
            for(int j = i - 1;j >= 0;j--){
                if (sym[j] == 0) {
                    if (nums[i] != nums[j]) {
                        if (dp[j] + 1 > dp[i]) {
                            dp[i] = dp[j] + 1;
                            sym[i] = (nums[i] > nums[j]) ? 1 : -1;
                        }
                    }
                }
                else if(nums[i] > nums[j]&&sym[j] == -1){
                    // dp[i] = max(dp[i],dp[j] + 1);
                    // sym[i] = dp[i] < dp[j] + 1?1:sym[i];
                    //隐形bug：此时dp[i]已经更新了，不能再判断了！！！
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        sym[i] = 1;
                    }
                }
                else if(nums[i] < nums[j]&&sym[j] == 1){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        sym[i] = -1;
                    }
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
