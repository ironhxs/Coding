// 或运算的最小翻转次数
// 关键点: 分析(a|b)与c的差异位，根据a&b判断需要翻转的次数
// 易错点: 理解两种情况：缺少1(翻转1次)和多余1(可能翻转1次或2次)
// 日期: 2025.08.06

#include <iostream>
using namespace std;

//算法1: 位运算分析法
class Solution {
public:
    int minFlips(int a, int b, int c) {
        //将(a|b)与c不同的位置1得到temp
        int temp = (a|b)^c,ret = 0;;
        //a&b：用来判断(a|b)某位多1时，a与b需要更改的次数
        int temp2 = a&b;
        while(temp){
            //取右边第一个1，即第一个不同的位分析
            int temp3 = temp&(-temp);
            //此时少1或多一个1，仅需反转一次
            if(!(temp3&temp2))
                ret++;
            //此时多两个1，需反转两次
            else{
                    ret += 2;
            }
            temp&=(temp - 1);
        }
        return ret;
    }
};

//算法2: 逐位分析法 (更直观)
class Solution2 {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        
        while(a || b || c) {
            int bitA = a & 1;
            int bitB = b & 1;
            int bitC = c & 1;
            int orResult = bitA | bitB;
            
            if(orResult != bitC) {
                if(bitC == 1) {
                    // 需要将0变成1，翻转a或b其中一个
                    flips += 1;
                } else {
                    // 需要将1变成0
                    if(bitA == 1 && bitB == 1) {
                        // 两个都是1，需要翻转两次
                        flips += 2;
                    } else {
                        // 只有一个是1，翻转一次
                        flips += 1;
                    }
                }
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return flips;
    }
};

//算法3: 内置函数法
class Solution3 {
public:
    int minFlips(int a, int b, int c) {
        // 需要从0变1的位数
        int need_set = c & ~(a | b);
        // 需要从1变0的位数  
        int need_clear = (a | b) & ~c;
        
        // 需要从0变1：翻转1次
        // 需要从1变0：如果a和b都是1则翻转2次，否则翻转1次
        return __builtin_popcount(need_set) + 
               __builtin_popcount(need_clear) + 
               __builtin_popcount(a & b & need_clear);
    }
};
