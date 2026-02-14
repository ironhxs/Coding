// 组合
// 关键点: 回溯模板，start 控制起始位置避免重复
// 易错点: 收集结果在 path.size() == k 时
// 日期: 2026.02.12

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> path;
        auto backtracking = [&](auto&& self,int start)->void{
            if(path.size() == k){
                ret.push_back(path);
                return;
            }
            for(int i = start; i <= n;i++){
                path.push_back(i);
                self(self,i + 1);
                path.pop_back();
            }
        };
        backtracking(backtracking,1);
        return ret;
    }
};
