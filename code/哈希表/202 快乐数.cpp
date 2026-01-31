// 快乐数
// 关键点: 使用哈希集合记录出现过的中间值，检测循环
// 易错点: 1.注意判断 1 的返回条件 2.每一步需要计算平方和
// 日期: 2026.01.31

#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
         auto get_num = [&](int n){
            int ret = 0;
            while(n){
                int re = n%10;
                ret += re * re;
                n/=10;
            }
            return ret;
         };
        unordered_set<int> s;
         while(1){
            n = get_num(n);
            if(s.count(n))
                if(n == 1)
                    return true;
                else
                    return false;
            else
                s.insert(n);
         }
    }
};
