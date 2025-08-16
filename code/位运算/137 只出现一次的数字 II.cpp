// 只出现一次的数字 II
// 关键点: 按位统计，每位出现次数对3取余，剩余的就是只出现一次的数字对应位
// 易错点: 使用bool()转换避免位权重影响，理解模3运算的数学原理
// 日期: 2025.08.06

#include <vector>
using namespace std;

//算法1: 按位统计+模3运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //肯定考虑位的关系
        //将所有数的对应位累加然后对所有位对3取余即可得到
        int ret = 0;
        for(int i = 0;i < 32;i++){
            //各位之和
            int sum=0;
            for(auto e:nums){
                //直接加的话结果是带位权重的
                sum+=bool(e&(1<<i));
            }
            sum%=3;
            ret |= (sum<<i);
        }
        return ret;
    }
};

//算法2: 数字电路状态机 (进阶解法)
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int num : nums) {
            // 状态转移：00->01->10->00
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;  // 出现1次的数字保存在ones中
    }
};

//算法3: 通用解法 (出现k次，其他出现m次)
class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
        // 针对本题：k=1, m=3
        int result = 0;
        for(int i = 0; i < 32; i++) {
            int count = 0;
            for(int num : nums) {
                if((num >> i) & 1) {
                    count++;
                }
            }
            if(count % 3 != 0) {  // 不能被3整除说明目标数字在此位为1
                result |= (1 << i);
            }
        }
        return result;
    }
};
