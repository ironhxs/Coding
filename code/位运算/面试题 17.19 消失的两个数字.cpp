// 消失的两个数字
// 关键点: 先异或得到a^b，再用最右边的1进行分组，分别求出a和b
// 易错点: 理解分组原理，掌握x&(-x)获取最右边1的技巧
// 日期: 2025.08.06

#include <vector>
using namespace std;

//算法1: 异或分组法
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        //本质就是只出现一次的数字(3)
        int _ab = 0;
        for(auto e:nums)
            _ab ^= e;
        for(int i = 1;i <= nums.size()+2;i++)
            _ab ^= i;
        //拿到a^b的右边第一个1，从而进行分类
        int temp = _ab&(- _ab);
        int a = 0,b = 0;
        for(auto e:nums){
            if(temp & e)
                 a ^= e;
            else
                 b ^=e;
        }
        for(int i = 1;i <= nums.size()+2;i++){
            if(temp & i)
                 a ^= i;
            else
                 b ^= i;
        }
        return {a,b};
    }
};

//算法2: 数学公式法
class Solution2 {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        long long sum1 = (long long)n * (n + 1) / 2;  // 1到n的和
        long long sum2 = 0;
        for(int num : nums) {
            sum2 += num;  // 数组元素的和
        }
        
        long long sumAB = sum1 - sum2;  // a + b
        
        // 计算1到n的平方和
        long long squareSum1 = (long long)n * (n + 1) * (2 * n + 1) / 6;
        long long squareSum2 = 0;
        for(int num : nums) {
            squareSum2 += (long long)num * num;
        }
        
        long long squareAB = squareSum1 - squareSum2;  // a² + b²
        
        // 利用 (a+b)² = a² + 2ab + b² 求出 ab
        long long productAB = (sumAB * sumAB - squareAB) / 2;
        
        // 解方程组：a + b = sumAB, a * b = productAB
        long long delta = sumAB * sumAB - 4 * productAB;
        int a = (sumAB + sqrt(delta)) / 2;
        int b = sumAB - a;
        
        return {a, b};
    }
};
