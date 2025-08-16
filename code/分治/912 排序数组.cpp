// 排序数组
// 关键点: 两种分治排序算法 - 快速排序(原地)与归并排序(稳定)
// 易错点: 快排迭代器边界处理，归并排序中指针偏移计算和回写操作
// 日期: 2025.08.12

#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//算法1: 三指针快速排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //初始化随机种子
        srand((unsigned int)time(nullptr));
        qsort(nums,nums.begin(),nums.end());
        return nums;
    }
    //递归程序
    void qsort(vector<int>& nums,vector<int>::iterator begin,vector<int>::iterator end){
        //递归出口
        if(begin >= end - 1)
            return;
        auto left = begin - 1,right = end;
        auto key = *(begin + rand()%(end - begin));
        //三指针优化版快速排序
        for(auto cur = begin;cur < right;cur++){
            if(*cur < key)
                swap(*(++left),*cur);
            else if(*cur > key)
                swap(*(--right),*(cur--));
        }
        qsort(nums,begin,left + 1);
        qsort(nums,right,end);
    }
};

//算法2: 归并排序
class Solution2 {
public:
    vector<int> ret;
    vector<int> sortArray(vector<int>& nums) {
        ret.resize(nums.size());
        MergeSort(nums,nums.begin(),nums.end());
        return ret;
    }
    void MergeSort(vector<int>& nums,vector<int>::iterator begin,vector<int>::iterator end){
        //递归结束条件
        if(begin >= end - 1)
            return;
        auto mid = begin + (end - begin + 1) / 2;
        //后序遍历
        MergeSort(nums,begin,mid);
        MergeSort(nums,mid,end);
        //想清楚每个变量的作用域
        auto left = begin,right = mid;
        auto p = ret.begin() + (begin - nums.begin()); 
        //归并
       while(left < mid && right < end){
            if(*left < *right)
                *(p++) = *(left++);
            else
                *(p++) = *(right++);
        }
        //处理未处理完的那个子数组
        while(left < mid)
            *(p++) = *(left++);
        while(right < end)
            *(p++) = *(right++);
        //将排序后的结果写入原数组，方便进一步归并排序
        auto tp = ret.begin() + (begin - nums.begin()); 
        while(begin < end) 
            *(begin++) = *(tp++);
    }
};
