// 最大连续1的个数 III
// 关键点: 滑动窗口维护最多k个0的最长子数组
// 日期: 2025.08.05

# include <vector>
# include <algorithm>
using namespace std;

//算法1: 滑动窗口
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int length = 0,count_0 = 0;//记录零的个数
        auto left = nums.begin(),right = left;
        for(;right < nums.end();right++){
            if(!*right)
                count_0++;
            //如果0超个数就left右移
            while(count_0 > k){
                if(!*left)
                    count_0--;
                left++;
            }
            length = max(length,(int)(right - left + 1)); 
        }
        return length;
    }
};
