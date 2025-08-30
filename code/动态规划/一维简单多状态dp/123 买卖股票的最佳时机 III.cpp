// 123 买卖股票的最佳时机 III
// 关键点: 四状态dp：第一次买、第一次卖、第二次买、第二次卖
// 易错点: 两次交易的状态转移
// 日期: 2025.08.30

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> first_buy(n + 1,0);
        auto first_sell = first_buy;
        auto second_buy = first_buy;
        auto second_sell = first_buy;
        first_buy[0] = - prices[0];
        second_buy[0] = - prices[0];
        for(int i = 1;i <= n;i++){
            first_buy[i] = max(first_buy[i - 1],-prices[i - 1]);
            first_sell[i] = max(first_sell[i - 1],first_buy[i - 1] + prices[i - 1]);
            second_buy[i] = max(second_buy[i - 1],first_sell[i - 1] - prices[i - 1]);
            second_sell[i] = max(second_sell[i - 1],second_buy[i - 1] + prices[i - 1]);
        } 
        return second_sell[n];
    }
};
