// 467 环绕字符串中唯一的子字符串
// 关键点: 建表，到i位置的最长子串的长度
// 易错点: 与前一个字符相邻的判断 (s[i] - s[i-1] + 26)%26 == 1
// 日期: 2025.08.31

#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        //建表
        //到i位置的最长子串的长度
        vector<int> dp(n,1);
        for(int i = 1;i <= n;i++){
            //与前一个字符相邻
            if((s[i] - s[i - 1] + 26)%26 == 1)
                dp[i] = dp[i - 1] + 1;
        }
        vector<int> hash_map(26,0);
        for(int i = 0;i < n;i++){
            int j = s[i] - 'a';
            hash_map[j] = max(dp[i],hash_map[j]); 
        }
        return accumulate(hash_map.begin(),hash_map.end(),0);
    }
};
