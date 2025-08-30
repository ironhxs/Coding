// LCR 091 粉刷房子
// 关键点: 三状态dp，每个房子有三种颜色选择，相邻房子不能同色
// 易错点: 什么拷贝？auto green = red; auto blue = red;
// 日期: 2025.08.30

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(); 
        vector<int> red(n + 1,0);
        //什么拷贝？
        auto green = red;
        auto blue = red;
        for(int i = 1;i <= n;i++){
            red[i] = min(blue[i - 1],green[i - 1]) + costs[i - 1][0];
            blue[i] = min(red[i - 1],green[i - 1]) + costs[i - 1][1];
            green[i] = min(blue[i - 1],red[i - 1]) + costs[i - 1][2];
        }
        return min(blue[n],min(green[n],red[n]));
    }
};
