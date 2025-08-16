# include <vector>
using namespace std;
//如果理解了端二分的深层含义，这道题会发现和山峰数组那个一模一样
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        auto left = nums.begin(),right = nums.end() - 1;
        while(left < right){
            auto mid = left + (right - left)/2;
            if(*mid < *(mid + 1))
                left = mid +1;
            else
                right = mid;
        }
        return int(left - nums.begin());
    }
};