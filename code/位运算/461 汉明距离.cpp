// 汉明距离
// 关键点: 逐位比较两个数的对应位是否不同，或者异或后统计1的个数
// 易错点: 位运算优先级，括号的使用
// 日期: 2025.08.06

#include <iostream>
using namespace std;

//算法1: 逐位比较法
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;
        //想到的思路比较多，但是还是采用了笨办法
        //1. 挨个比较
        //2. 异或一下，转化为统计1的个数
        //3. 利用取某数的右边第一个1，与消除某数的右边第一个1
        for(int i = 0;i < 32;i++){
            if((x&(1<<i))!=(y&(1<<i)))
                ret++;    
            }
        return ret;
    }
};

//算法2: 异或+统计1的个数
class Solution2 {
public:
    int hammingDistance(int x, int y) {
        int xor_result = x ^ y;  // 异或得到不同的位
        int ret = 0;
        
        // 统计异或结果中1的个数
        for(int i = 0; i < 32; i++){
            if(xor_result & (1<<i))
                ret++;
        }
        return ret;
    }
};

//算法3: Brian Kernighan算法 (消除最右边的1)
class Solution3 {
public:
    int hammingDistance(int x, int y) {
        int xor_result = x ^ y;
        int ret = 0;
        
        // 每次消除最右边的1
        while(xor_result) {
            xor_result &= (xor_result - 1);  // 消除最右边的1
            ret++;
        }
        return ret;
    }
};
