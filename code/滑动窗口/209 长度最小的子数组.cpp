// 长度最小的子数组
// 关键点: 滑动窗口找到和大于等于target的最短子数组
// 日期: 2025.08.05

# include <vector>
# include <algorithm>
# include <climits>
using namespace std;

//算法1: 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX,sum=0;
        auto left = nums.begin(),right = left;
        for(;right<nums.end();right++){
            sum+=*right;
            while(sum>=target){
                len = min((int)(right - left + 1),len);
                sum -= *left;
                left ++;
             }
        }
        return (len==INT_MAX?0:len);
    }
};
