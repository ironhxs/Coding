// 全排列 II
// 关键点: 排序 + used 数组同时实现同层去重和已选标记
// 易错点: 去重条件 i>0 && nums[i-1]==nums[i] && !used[i-1]（前一个未使用说明是同层）
// 日期: 2026.02.13

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        int n = nums.size();
        vector<bool> used(n,false);
        sort(nums.begin(),nums.end());
        auto backtracking = [&](auto&& self)->void{
            if(path.size() == n){
                ret.push_back(path);
                return;
            }
            for(int i = 0;i <= n - 1;i++){
                if(used[i] ||(i > 0 && nums[i - 1] == nums[i] && !used[i - 1]))
                    continue;
                path.push_back(nums[i]);
                used[i] = true;
                self(self);
                path.pop_back();
                used[i] = false;
            }
        };
        backtracking(backtracking);
        return ret;
    }
};
