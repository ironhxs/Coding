# include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //用迭代器一定要确保非空，否则迭代器失效
        if(nums.empty())
            return {-1,-1};
        auto left = nums.begin(),right = nums.end()-1;
        while(left < right){
            auto mid = left + (right - left)/2;
            if(*mid < target)
                left = mid + 1;
            else
                right = mid;
        }
        //如果结束时没找到，则直接返回
        if(*left != target)
            return {-1,-1};
        auto _begin = left;
        right = nums.end()-1;
        while(left < right){
            auto mid = left + (right - left + 1)/2;
            if(*mid > target)
                right = mid - 1;
            else
                left = mid;
        }
        //迭代器相减默认为long，从64位整数到32位整数的转换被认为是"窄化转换"，C++11标准禁止在初始化列表中进行隐式的窄化转换
        return {(int)(_begin-nums.begin()),(int)(right - nums.begin())};
    }
};