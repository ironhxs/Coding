// 139 单词拆分
// 关键点: 字符串hash + dp，判断子串是否在字典中
// 易错点: 字符串拼接 s = ' ' + s 和索引调整
// 日期: 2025.08.31

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> hash(wordDict.begin(),wordDict.end());
        //i及之前的能否由wordDict中单词组成
        vector<bool> dp(n + 1,false);
        //初始化
        dp[0] = true;
        s = ' ' + s;
        for(int i = 1;i <= n;i++){
            for(int j = i - 1;j >= 0;j--){
                 if(dp[j]&&hash.count(s.substr(j + 1,i - j))){
                    dp[i] = true;
                    break;
                }   
            }
        }
        return dp[n];
    }
};
