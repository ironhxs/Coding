// 比特位计数
// 关键点: 动态规划，利用i&(i-1)消除最右边1的性质建立递推关系
// 易错点: 理解i&(i-1)的含义，初始化ret[0]=0
// 日期: 2025.08.06

#include <vector>
using namespace std;

//算法1: Brian Kernighan DP (最优解)
class Solution {
public:
    vector<int> countBits(int n) {
        //逐个统计确实简单，于是想其他的思路
        //考虑dp，找关系
        //1. 根据n&(n-1)与n之间位的关系
        //2. 根据(n/2)与n之间位的关系
        //3. 根据n与n-highest之间位的关系
        vector<int> ret(n + 1);
        //只需要初始化0即可（隐式），从1开始
        for(int i = 1;i <= n;i++){
            ret[i] = ret[i&(i -1)] + 1;
        }
        return ret;
    }
};

//算法2: 奇偶性DP
class Solution2 {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1);
        for(int i = 1; i <= n; i++){
            // 偶数：右移一位，1的个数不变
            // 奇数：右移一位再加1
            ret[i] = ret[i >> 1] + (i & 1);
        }
        return ret;
    }
};

//算法3: 最高有效位DP
class Solution3 {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1);
        int highBit = 0;
        for(int i = 1; i <= n; i++){
            if((i & (i - 1)) == 0){  // i是2的幂
                highBit = i;
            }
            ret[i] = ret[i - highBit] + 1;
        }
        return ret;
    }
};
