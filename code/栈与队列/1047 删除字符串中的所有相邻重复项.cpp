// 删除字符串中的所有相邻重复项
// 关键点: 用字符串模拟栈，相邻相同则弹出
// 易错点: 空栈判断
// 日期: 2026.02.05

#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ret;
        for(auto & ch:s){
            if(ret.empty()||ch != ret.back())
                ret.push_back(ch);
            else
                ret.pop_back();
        }
        return ret;
    }
};
