// 三数之和（哈希表实现）
// 关键点: 排序+哈希表查找补数，去重处理
// 易错点: 必要的去重，哈希表只查找未用过的数
// 日期: 2026.02.04

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i <= n - 1;i++){
            int a = nums[i];
            //剪枝
            if(a > 0)
                continue;
            //必要去重
            if(i > 0 && nums[i-1] == a)
                continue;
            unordered_set<int> us;
            for(int j = i + 1;j <= n - 1;j++){
                //必要去重
                if(j > i + 2 && nums[j] == nums[j - 1] && nums[j-2] == nums[j - 1])
                    continue;
                if(us.count(-a - nums[j])){
                    us.erase(-a - nums[j]);
                    ret.push_back({a,nums[j],-a - nums[j]});
                }
                else
                    us.insert(nums[j]);
            }
        }
        return ret;
    }
};
