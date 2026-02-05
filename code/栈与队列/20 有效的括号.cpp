// 有效的括号
// 关键点: 栈匹配，遇到右括号检查栈顶是否配对
// 易错点: 栈为空时不能取 top，最后栈需为空才有效
// 日期: 2026.02.05

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        auto isPair = [&](char ch){
            switch(ch){
                 case '(':
                    return st.top() ==')';
                case '{':
                    return st.top() =='}';
                case '[':
                    return st.top() ==']';
                default:
                    return false;
            }
        };
        while(!s.empty()){
            char ch = s.back();
            s.pop_back();
            if(!st.empty()){
                if(isPair(ch)){
                    st.pop();
                    continue;
                }
            }
            st.push(ch);
        }
        return st.empty();
    }
};
