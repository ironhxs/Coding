// 螺旋矩阵 II
// 关键点: 按层模拟，每层按上右下左四个方向填充
// 易错点: 1.奇数n时中心点单独处理 2.每层边界控制 i 到 n-i-1
// 日期: 2026.01.30

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n,vector<int>(n,0));
        int start_x = 0;
        int start_y = 0;
        int j = 1;
        for(int i = 0;i < n/2;i++){
            for(int k = i;k < n - i - 1;k++)
                ret[i][k] = j++;
            for(int k = i;k < n - i - 1;k++)
                ret[k][n - i - 1] = j++;
            for(int k =  n - i - 1;k > i;k--)
                ret[n - i - 1][k] = j++;
            for(int k = n - i - 1;k > i;k--)
                ret[k][i] = j++;
        }
        if(n % 2)
            ret[n/2][n/2] = n*n;
        return ret;
    }
};
