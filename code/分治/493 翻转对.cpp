// 翻转对
// 关键点: 归并排序统计翻转对，需要在归并过程中统计满足nums[i]>2*nums[j]的对数
// 易错点: 数值溢出处理(long long)，双重循环统计逻辑，负数情况考虑
// 日期: 2025.08.12

#include <vector>
using namespace std;

//算法1: 归并排序统计翻转对
class Solution {
public:
    vector<int> temp;
    int ret = 0;
    int reversePairs(vector<int>& nums) {
        if(nums.empty())
            return 0;
        //一定别忘记，否则会迭代器失效
        temp.resize(nums.size());
        Merge_Sort(nums,nums.begin(),nums.end());
        return ret;
    }
    void Merge_Sort(vector<int>& nums,vector<int>::iterator begin,vector<int>::iterator end){
        if(begin >= end - 1)
            return;
        auto mid = begin + (end - begin + 1) / 2;
        auto left = begin,right = mid;
        Merge_Sort(nums,begin,mid);
        Merge_Sort(nums,mid,end);
        auto tp = temp.begin() + (begin - nums.begin());
        while(left < mid&&right < end){
            //不要忘了考虑负数情况
            if(*left < *right){
                auto pp = right;
                while(pp < end && *left > ((long long)(*pp) * 2))
                        pp++;
                ret += pp - right;
                *(tp++) = *(left++);
            }
            else{
                auto pp = left;
                //注意题目说单个元素就是int范围，那做运算很有可能超，所以用long long
                while(pp < mid && *pp <= ((long long)(*right) * 2))
                        pp++;
                ret += mid - pp;
                *(tp++) = *(right++);
            }
        }
        //解决未处理的数组
        while(left < mid)
            *(tp++) = *(left++);
        while(right < end)
            *(tp++) = *(right++);
        //更新原数组
        while(end > begin)
            *--end = *--tp;
    }
};
