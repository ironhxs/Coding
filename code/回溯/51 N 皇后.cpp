// N 皇后
// 关键点: 逐行放置，用三个数组标记列、左对角线、右对角线
// 易错点: 左对角线索引 i-j+n-1，右对角线索引 i+j
// 日期: 2026.02.13

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<bool>usedV(n,false);
        vector<bool>usedL(2 * n - 1,false);
        vector<bool>usedR(2 * n - 1,false);
        vector<string> path;
        auto backtracking = [&](auto&& self)->void{
            if(path.size() == n){
                ret.push_back(path);
                return;
            }
            for(int i = 0; i <= n - 1; i++){
                int j = path.size();
                if(usedV[i] || usedL[i - j + n - 1] || usedR[i + j])
                    continue;
                string temp = "";
                for(int j = 0; j < i;j++)
                    temp += '.';
                temp += 'Q';
                for(int j = i + 1;j <= n - 1;j++)
                    temp += '.';
                path.push_back(temp);
                usedV[i] = true;
                usedL[i - j + n - 1] = true;
                usedR[i + j] = true;
                self(self);
                path.pop_back();
                usedV[i] = false;
                usedL[i - j + n - 1] = false;
                usedR[i + j] = false;
            }
        };
        backtracking(backtracking);
        return ret;
    }
};
