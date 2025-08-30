// 121 买卖股票的最佳时机
// 关键点: 贪心算法，维护最小买入价格和最大利润
// 易错点: dp不可以解决？
// 日期: 2025.08.30

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp不可以解决？
        int n = prices.size();
        int _max = 0,_min = INT_MAX;
        for(auto price:prices){
            _max = max(_max,price - _min);
            _min = min(_min,price);
        }
        return _max;
    }
};
