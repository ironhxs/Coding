// 找出字符串中第一个匹配项的下标（KMP）
// 关键点: KMP 算法，next 数组预处理
// 易错点: needle 为空时返回 0，注意边界
// 日期: 2026.02.05

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ret = -1;
        int n = needle.size();
        int m = haystack.size();
        if(needle.empty())
            return  0;
        vector<int> next(n,0);
        auto getNext = [&](){
            int j = 0;
            for(int i = 1;i <= n - 1;i++){
                while(j > 0&&needle[i]!=needle[j]){
                    j = next[j - 1];
                }
                if(needle[i]==needle[j])
                    j++;
                next[i] = j;
            }
        };
        getNext();
        int j = 0;
        for(int i = 0;i <= m - 1;i++){
            while(j > 0&&needle[j] != haystack[i])
                j = next[j - 1];
            if(needle[j] == haystack[i])
                j++;
            if(j == n){
                ret = i - j + 1;
                break;
            }
        }
        return ret;
    }
};
