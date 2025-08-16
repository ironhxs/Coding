// 将 x 减到 0 的最小操作数
// 关键点: 正难则反，转化为找出最长子数组之和等于sum-x
// 易错点: 初始化应当区分不可能的长度，注意越界问题
// 日期: 2025.08.05

# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

//算法1: 滑动窗口（逆向思维）
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int target = accumulate(nums.begin(),nums.end(),0) - x;
        //因为条件才能改变长度，所以初始化应当区分，所以应当初始化为不可能的长度
        int sum = 0,length = -1;
        for(auto left = nums.begin(),right = left;right<nums.end();right++) {
            sum += *right;
            //之前没注意这里，有可能越界
            while(left <= right&&sum > target){
                sum -= *left;
                left ++;
            }
            if(sum == target)
                length = max(length,(int)(right - left + 1));
        }
        return (length==-1?-1:(nums.size() - length));
    }
};
