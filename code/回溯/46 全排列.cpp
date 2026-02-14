// 全排列
// 关键点: 排列不需要 start，用 used 数组标记已选元素
// 易错点: 每次从 0 开始遍历，跳过 used[i]=true 的元素
// 日期: 2026.02.13

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        vector<int> path;
        vector<bool> used(n,false);
        auto backtracking = [&](auto&& self)->void{
            if(path.size() == n){
                ret.push_back(path);
                return;
            }        
            for(int i = 0;i <= n - 1;i++){
                if(used[i])
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
