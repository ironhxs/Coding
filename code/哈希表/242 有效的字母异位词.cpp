// 有效的字母异位词
// 关键点: 计数数组/哈希表统计字符频次并比较
// 易错点: 长度不同直接返回 false
// 日期: 2026.01.31

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        vector<int> s_hash(26,0);
        vector<int> t_hash(26,0);
        int n = s.size();
        for(int i = 0;i <= n - 1;i++){
            s_hash[s[i] - 'a']++;
            t_hash[t[i] - 'a']++;
        }
        return s_hash == t_hash;
    }
};
