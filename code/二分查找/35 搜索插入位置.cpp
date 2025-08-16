# include <vector>
using namespace std;
//分析可得要找出>=区间的最左端即要用左端二分查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //特殊情况，大于最大时
        //if(target > nums[-1])
        //不支持负索引
        if(target > *(nums.end()-1))
            return nums.size();
        else{
            auto left = nums.begin(),right = nums.end()-1;
            while(left < right){
                auto mid = left + (right - left)/2;
                if(*mid < target)
                    left = mid + 1;
                else    
                    right = mid;
            }
            return (int)(left - nums.begin());
        }
    }
};