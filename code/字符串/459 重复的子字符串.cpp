// 重复的子字符串（KMP）
// 关键点: KMP next 数组，判断是否能整除周期
// 易错点: next[n-1] == 0 时不能整除
// 日期: 2026.02.05

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> next(n,0);
        auto getNext = [&](){
            int j = 0;
            for(int i = 1;i <= n - 1;i++){
                while(j > 0&&s[j] != s[i])
                    j = next[j - 1];
                if(s[j] == s[i])
                    j++;
                next[i] = j;
            }
        };
        getNext();
        if(next[n - 1] != 0&&n%(n - (next[n-1])) == 0)
            return true;
        return false;
    }
};
