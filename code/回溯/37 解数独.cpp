// 解数独
// 关键点: 三个约束数组（行/列/宫），逐格尝试 1-9 填入
// 易错点: 找到空格尝试所有数字后仍无解需返回 false（关键剪枝）
// 日期: 2026.02.13

#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board[0].size();
        vector<vector<bool>> usedH(n,vector<bool>(10,false));
        vector<vector<bool>> usedV(n,vector<bool>(10,false));
        vector<vector<vector<bool>>> usedB(3,vector<vector<bool>>(3,vector<bool>(10,false)));
        int finish = 0;
        for(int i = 0;i <= n - 1;i++){
            for(int j = 0;j <= n - 1; j++){
                if(board[i][j] != '.'){
                    int temp = board[i][j] - '0';
                    usedH[i][temp] = true;
                    usedV[j][temp] = true;
                    usedB[i/3][j/3][temp] = true;
                    finish++;
                }
            }
        }
        auto backtracking = [&](auto&&self,int starti,int startj)->bool{
            if(finish == 81)
                return true;
            for(int i = starti; i <= 8;i++){
                if(i != starti)
                    startj = 0;
                for(int j = startj;j <= 8;j++){
                    if(board[i][j] == '.'){
                        for(int k = 1; k<= 9;k++){
                            int temp = k;
                            if(usedH[i][temp] || usedV[j][temp] || usedB[i/3][j/3][temp]){
                                continue;
                            }
                            else{
                                usedH[i][temp] = true;
                                usedV[j][temp] = true;
                                usedB[i/3][j/3][temp] = true;
                                finish++;
                                board[i][j] = '0' + k;
                                int si = j + 1 > 8?i + 1:i;
                                int sj = j + 1 > 8?0:j + 1;
                                if(self(self,si,sj))
                                    return true;
                                usedH[i][temp] = false;
                                usedV[j][temp] = false;
                                usedB[i/3][j/3][temp] = false;
                                finish--;
                                board[i][j] = '.';
                            }
                        }
                        //关键剪枝
                        return false;
                    }
                    else
                        continue;
                }
            }
            return false;
        };
        backtracking(backtracking,0,0);
    }
};
