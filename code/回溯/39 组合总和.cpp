// 组合总和
// 关键点: 元素可重复使用，递归时 start 不加 1
// 易错点: 剪枝 sum + candidates[i] > target 时跳过
// 日期: 2026.02.12

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> path;
        int sum = 0;
        int n = candidates.size();
        auto backTracking = [&](auto&& self,int start)->void{
            if(sum == target){
                ret.push_back(path);
                return;
            }
            for(int i = start;i <= n - 1;i++){
                if(sum + candidates[i] > target)
                    continue;
                path.push_back(candidates[i]);
                sum += candidates[i];
                self(self,i);
                path.pop_back();
                sum -= candidates[i];
            }
        };
        backTracking(backTracking,0);
        return ret;
    }
};
