// 逆波兰表达式求值
// 关键点: 栈存操作数，遇到运算符弹出两个操作数计算后压栈
// 易错点: 注意 left/right 顺序，先弹出的是 right
// 日期: 2026.02.05

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> opNum;
        auto Operate = [](string op,int left,int right){
            switch(op[0]){
                case('+'):
                    return left + right;
                case('-'):
                    return left - right;
                case('*'):
                    return left * right;
                case('/'):
                    return left / right;
                default:
                    return 0;
            }
        };
        for(auto & e : tokens){
            if(e == "+"||e == "-"||e == "*"||e == "/"){
                int right = opNum.top();
                opNum.pop();
                int left = opNum.top();
                opNum.pop();
               int result = Operate(e,left,right);
               opNum.push(result);
            }
            else
                opNum.push(stoi(e));
        }
        return opNum.top();
    }
};
