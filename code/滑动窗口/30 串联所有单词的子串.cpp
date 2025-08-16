// 串联所有单词的子串
// 关键点: 分组滑动窗口+哈希表，按单词长度分组避免重复计算
// 易错点: const_cast语法错误，窗口边界计算
// 日期: 2025.08.06

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//算法1: 分组滑动窗口
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
         int m=words.size(),len=words[0].size();//前者是单词种类，后者是一个单词的长度（决定窗口大小）
         vector<int> ret;//结果集
         unordered_map<string,int> hash1;//统计words
         for(auto&str:words) ++hash1[str];
         for(int i=0;i<len;++i){
            unordered_map<string,int> hash2;//统计s
            for(int left=i,right=i,count=0;right+len-1<s.size();right+=len){
                string in=s.substr(right,len);
                if(++hash2[in]<=hash1[in]) ++count;
                if(right-left+1>len*m){//这时候得出了
                    string out=s.substr(left,len);
                    if(hash2[out]--<=hash1[out]) --count;
                    left+=len;
                }
                if(count==m) ret.emplace_back(left);
            }
         }
         return ret;
    }
};
