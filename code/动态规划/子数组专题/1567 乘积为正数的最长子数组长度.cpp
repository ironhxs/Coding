// 1567 乘积为正数的最长子数组长度
// 关键点: 维护正数和负数两个状态，根据当前元素正负性转移
// 易错点: 前提是前面已经有个负数了
// 日期: 2025.08.30

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n + 1,0);
        vector<int> neg(n + 1,0);
        for(int i = 1;i <= n;i++){
            int temp = nums[i - 1];
            if(temp > 0){
                pos[i] = pos[i - 1] + 1;
                //前提是前面已经有个负数了
                if(neg[i - 1] > 0)
                    neg[i] = neg[i - 1] + 1;
            }
            else if(temp < 0){
                //前提是前面已经有个负数了
                if(neg[i - 1] > 0)
                    pos[i] = neg[i - 1] + 1;
                neg[i] = pos[i - 1] + 1;
            }
        }
        return *max_element(pos.begin() + 1,pos.end());
    }
};
