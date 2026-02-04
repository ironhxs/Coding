// 四数之和（哈希表实现）
// 关键点: 排序+哈希表查找补数，去重处理
// 易错点: long 溢出处理，必要的去重
// 日期: 2026.02.04

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i <= n - 1;i++){
            int a = nums[i];
            //谨慎剪枝，可能是负数
            if(a > target && nums[i] >= 0)
                break;
            if(i > 0 && a == nums[i - 1])
                continue;
            for(int j = i + 1; j <= n - 1;j++){
                int b = nums[j];
                if(j > i + 1 && b == nums[j - 1])
                    continue;
                unordered_set<int> us;
                for(int k = j + 1;k <= n - 1;k++){
                    if(k > j + 2 && nums[k] == nums[k - 1] && nums[k - 1] == nums[k - 2])
                        continue;
                    if(long(target) - a - b - nums[k] >= INT_MIN&&long(target) - a - b - nums[k] <= INT_MAX&&us.count(long(target) - a - b - nums[k])){
                        us.erase(long(target) - a - b - nums[k]);
                        ret.push_back({a,b,nums[k],int(long(target) - a - b - nums[k])});
                    }
                    else{
                        us.insert(nums[k]);
                    }
                }
            }
        }
        return ret;
    }
};
