// 无重复字符的最长子串
// 关键点: 滑动窗口维护无重复字符的最长子串
// 日期: 2025.08.05

# include <string>
# include <algorithm>
using namespace std;

//算法1: 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        //
        int _hash[128]{};
        for(auto left = s.begin(),right = left;right<s.end();right ++){
            _hash[*right]++;
            while(_hash[*right]>1){
                _hash[*left]--;
                left++;
            }
            len = max((int)(right - left +1),len);
        }
        return len;
    }
};
