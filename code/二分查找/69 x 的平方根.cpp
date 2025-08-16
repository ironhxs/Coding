//理解左右端二分查找的本质：
//1. 左端：找到>=区间的左端（即该区间的最小值）
//2. 右端：找到<=区间的右端（即该区间的最大值）
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        long long mid;
        while(left < right){
            //一直以为溢出是接受的容器不够大，但是cpp运算规则是：
            //1. 表达式独立求值：(right - left + 1) 这个子表达式会独立计算
            //2. 操作数决定类型：因为 right、left 都是 int，所以整个子表达式用 int 运算
            //溢出在子表达式中发生：当结果超过 int 范围时，溢出就发生了
            //即：要确保每个子表达式都不溢出
            //mid = (long long)left + (long long)(right - left + 1)/2;
            mid = (long long)left + ((long long)right - left + 1)/2;
            if(mid * mid > x)
                right = mid - 1;
            else
                left = mid;
        }
        return right;
    }
};