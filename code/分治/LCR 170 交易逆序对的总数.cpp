// 交易逆序对的总数
// 关键点: 归并排序统计逆序对，利用归并过程中的先后信息统计跨区间逆序对
// 易错点: 逆序对计数逻辑(mid-left)，边界条件处理，迭代器失效问题
// 日期: 2025.08.12

#include <vector>
using namespace std;

//算法1: 归并排序统计逆序对
class Solution {
public:
    vector<int> temp;
    int ret = 0;
    int reversePairs(vector<int>& record) {
        //1.遍历的方法时间复杂度太高了
        // for(auto left = record.begin();left < record.end();left++){
        //     for(auto right = left + 1;right < record.end();right++)
        //         if(*right < *left)
        //             ret++;
        //2.归并（为何不可用快速排序：归并自带先后信息）
        //用的迭代器，一定要注意迭代器失效问题，题目表示长度可以为0，即可能为空
        if (record.size() < 1) return 0;
        temp.resize(record.size());
        Merge_Sort(record,record.begin(),record.end());
        return ret;
        }
        void Merge_Sort(vector<int>& record,vector<int>::iterator begin,vector<int>::iterator end){
            //递归结束条件
            if(begin >= end - 1)
                return;
            auto mid = begin + (end - begin + 1)/2;
            auto p = temp.begin() + (begin - record.begin());
            //后序遍历
            Merge_Sort(record,begin,mid);
            Merge_Sort(record,mid,end);
            auto left = begin,right = mid;
            for(;left < mid&&right < end;){
                if(*left <= *right)
                    *p++ = *left++;
                else{
                    *p++ = *right++;
                    // ret++;
                    //应该是加左边剩下元素的个数，因为都比他大
                    ret += mid - left;
                }
            }
            //处理未处理完的子数组
            while(left < mid)
                *p++ = *left++;
            while(right < end)
                *p++ = *right++;
            //写回原数组
            while(end > begin)
                *--end = *--p;
        }
};
