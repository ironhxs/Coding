// 解码方法
// 关键点: 一维DP，考虑单字符和双字符两种情况
// 易错点: 字符'0'的处理，双字符范围判断(10-26)
// 日期: 2024.12.19

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size() + 1);
        //若分别用下标和迭代器，保证begin相同，否则逻辑易混乱
        auto front = s.begin() - 1;
        dp[0] = 1;
        dp[1] = (*(front + 1) == '0'?0:1);
        for(int i = 2;i <= s.size();i++){
            //单字符出现时
            if(*(front + i) != '0')
                dp[i] += dp[i - 1];
            //与前一个组成双字符时
            int temp = *(front + i)- '0' + (*(front + i - 1) - '0') * 10; 
            if(temp>=10 && temp<=26)
                dp[i] += dp[i - 2];
        }
        return dp[s.size()];
    }
};
