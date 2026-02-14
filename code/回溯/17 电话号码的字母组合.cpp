// 电话号码的字母组合
// 关键点: 每层递归处理一个数字，遍历该数字对应的所有字母
// 易错点: 不同数字间是组合关系，不需要 start 参数
// 日期: 2026.02.12

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string path;
        int n = digits.size();
        unordered_map<char,string> um = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        auto backtracking = [&](auto&& self,int k)->void{
            if(path.size() == n){
                ret.push_back(path);
                return;
            }
            string s = um[digits[k]];
            for(char ch : s){
                path.push_back(ch);
                self(self,k + 1);
                path.pop_back();
            }
        };
        backtracking(backtracking,0);
        return ret;
    }
};
