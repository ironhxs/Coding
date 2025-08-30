// 122 买卖股票的最佳时机 II
// 关键点: 三状态dp：买、卖、保持
// 易错点: 初始化(根据填表顺序和转移方程)
// 日期: 2025.08.30

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //三状态：买;卖;保持;
        int n = prices.size();
        vector<int> buy(n + 1,0);
        auto sell = buy;
        //初始化(根据填表顺序和转移方程)
        buy[0] = -prices[0];
        for(int i = 1;i <= n;i++){
            buy[i] = max(buy[i - 1],sell[i - 1] - prices[i - 1]);
            sell[i] = max(sell[i - 1],buy[i - 1] + prices[i - 1]);
        }
        return max(buy[n],sell[n]);
    }
};
