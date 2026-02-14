// 组合总和 II
// 关键点: 排序 + 同层去重（i > start && candidates[i-1] == candidates[i]）
// 易错点: 去重是同层去重，不是同枝去重；需要先排序
// 日期: 2026.02.12

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> path;
        int sum = 0;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        auto backtracking = [&](auto&& self,int start)->void{
            if(sum == target){
                ret.push_back(path);
                return;
            }
            for(int i = start;i <= n - 1&&sum < target + candidates[i];i++){
                if(i > start && candidates[i - 1] == candidates[i])
                    continue;
                sum += candidates[i];
                path.push_back(candidates[i]);
                self(self,i + 1);
                sum -= candidates[i];
                path.pop_back();
            }
        };
        backtracking(backtracking,0);
        return ret;
    }
};
