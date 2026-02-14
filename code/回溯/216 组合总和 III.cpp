// 组合总和 III
// 关键点: 回溯 + 限制数字范围 1-9 且不重复
// 易错点: 终止条件同时判断 size == k 和 sum == n
// 日期: 2026.02.12

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> path;
        int sum = 0;
        auto backtracking = [&](auto&& self,int start)->void{
            if(path.size() == k){
                if(sum == n)
                    ret.push_back(path);
                return;
            }
            for(int i = start;i <= 9;i++){
                path.push_back(i);
                sum += i;
                self(self,i + 1);
                path.pop_back();
                sum -= i;
            }
        };
        backtracking(backtracking,1);
        return ret;
    }
};
