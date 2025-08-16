# include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto left = nums.begin(),right = nums.end()-1;
        while(left <= right){
            auto mid = left + (right - left)/2;
            if(*mid > target){
                right = mid - 1;
            }
            else if(*mid < target){
                left = mid + 1;
            }
            else
                return static_cast<int>(mid - nums.begin());
        }
       return -1;
    }
};