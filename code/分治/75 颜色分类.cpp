// 颜色分类
// 关键点: 三指针分区算法，荷兰国旗问题，一次遍历完成三分区
// 易错点: cur指针移动时机，交换后cur是否自增，边界处理
// 日期: 2025.08.12

#include <vector>
using namespace std;

//算法1: 三指针分区(荷兰国旗)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto left = nums.begin() - 1,right = nums.end(),cur = nums.begin();
        while(cur < right){
            if(*cur == 0)
                swap(*(cur++),*(++left));
            else if(*cur == 1)
                cur++;
            else
                swap(*cur,*(--right));
        }
    }
};
