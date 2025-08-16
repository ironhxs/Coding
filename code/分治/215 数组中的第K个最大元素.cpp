// 数组中的第K个最大元素
// 关键点: 快速选择算法(QuickSelect)，三指针分区优化，平均时间复杂度O(n)
// 易错点: 迭代器边界处理(begin-1)，递归区间判断逻辑，cur--后需重新检查
// 日期: 2025.08.12

#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//算法1: 快速选择 + 三指针分区
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand((unsigned int)time(nullptr));
        return qsort_find(nums,nums.begin(),nums.end(),k);
    }
    int qsort_find(vector<int>nums,vector<int>::iterator begin,vector<int>::iterator end,int k){
        //递归结束条件
        if(begin >= end - 1)
            return *begin;
        auto key = *(begin + rand()%(end - begin));
        auto left = begin - 1,right = end;
        //优化的三指针快速排序
        for(auto cur = begin;cur < right;cur++){
            if(*cur < key)
                swap(*cur,*(++left));
            else if(*cur > key)
                swap(*(cur--),*(--right));
        }
        //要认真思考=
        if(end - right >= k)
            return qsort_find(nums,right,end,k);
        else if(end - left -1 < k)
            return qsort_find(nums,begin,left + 1,k-(end - left - 1));
        else 
            return key;
    }
};
