// 库存管理 III
// 关键点: 快速选择变种，TopK最小元素问题，三指针分区优化
// 易错点: 递归条件判断逻辑，边界case处理，与215题思路相似但求最小K个
// 日期: 2025.08.12

#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//算法1: 快速选择TopK
class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        srand((unsigned int)time(nullptr));
        vector<int> temp{};
        qsort(stock,stock.begin(),stock.end(),cnt);
        for(int i = 0;i < cnt;i++)
            temp.push_back(stock[i]);
        return temp;
    }
    void qsort(vector<int>& stock,vector<int>::iterator begin ,vector<int>::iterator end,int cnt){
        //递归结束条件
        if(begin >= end - 1)
            return;
        auto left = begin - 1,right = end;
        auto key = *(begin + rand()%(end - begin));
        for(auto cur = begin;cur < right;cur++){
            if(*cur < key)
                swap(*cur,*(++left));
            else if(*cur > key)
                swap(*(cur--),*(--right));
        }
        if(left - begin + 1 > cnt)
            qsort(stock,begin,left+1,cnt);
        else if(cnt < right - begin + 1)
            return;
        else
            qsort(stock,right,end,cnt - (right - begin));
    }
};
