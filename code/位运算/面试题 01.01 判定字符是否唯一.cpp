// 判定字符是否唯一
// 关键点: 用int作为位图，每一位代表一个字符是否出现过
// 易错点: 字符范围假设(只考虑小写字母)，位运算的检查和设置操作
// 日期: 2025.08.06

#include <string>
#include <unordered_set>
using namespace std;

//算法1: 位图法 (最优解)
class Solution {
public:
    bool isUnique(string astr) {
        //用int位图
        int bit_map = 0;
        for(auto e:astr){
            //记录当前字符的id
            int temp = e - 'a'; 
            if(bit_map&(1<<temp))
                return false;
            else
                bit_map|=(1<<temp);
        }
        return true;
    }
};

//算法2: 位图法优化版 (处理所有ASCII字符)
class Solution2 {
public:
    bool isUnique(string astr) {
        if(astr.length() > 128) return false;  // ASCII字符最多128个
        
        int bit_map[4] = {0};  // 4个int覆盖128位
        for(char c : astr) {
            int pos = c;
            int index = pos / 32;      // 确定在哪个int中
            int offset = pos % 32;     // 确定在int的哪一位
            
            if(bit_map[index] & (1 << offset))
                return false;
            bit_map[index] |= (1 << offset);
        }
        return true;
    }
};

//算法3: 哈希集合法 (通用解法)
class Solution3 {
public:
    bool isUnique(string astr) {
        unordered_set<char> seen;
        for(char c : astr) {
            if(seen.count(c)) 
                return false;
            seen.insert(c);
        }
        return true;
    }
};

//算法4: 排序法 (不使用额外数据结构)
#include <algorithm>
class Solution4 {
public:
    bool isUnique(string astr) {
        sort(astr.begin(), astr.end());
        for(int i = 1; i < astr.length(); i++) {
            if(astr[i] == astr[i-1])
                return false;
        }
        return true;
    }
};
