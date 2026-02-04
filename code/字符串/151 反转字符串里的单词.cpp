// 反转字符串里的单词
// 关键点: 利用栈逆序单词，注意分割与去空格
// 易错点: 末尾多余空格处理
// 日期: 2026.02.05

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ret;
        int n = s.size();
        stack<string> st;
        auto _reverse = [&](int left,int right){
            //左闭右闭
            string t;
            while(left <= right){
                t += s[left++];
            }
            t += ' ';
            st.push(t);
        };
        int left = 0;
        for(int right = 0;right < n;right++){
            if(!isalnum(s[right]))
                continue;
            if(!isalnum(s[right + 1])){
                while(!isalnum(s[left]))
                    left++;
                _reverse(left,right);
                left = right + 1;
            }
        }
        while(!st.empty()){
            auto temp = st.top();
            ret += temp;
            st.pop();
        }
        ret.pop_back();
        return ret;
    }
};
