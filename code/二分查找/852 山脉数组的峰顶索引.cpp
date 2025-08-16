# include <vector>
using namespace std;
//拓展对端二分的理解：
//else条件的最左/右端 
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto left = arr.begin(), right = arr.end() - 1;
        while(left < right){
            auto mid = left + (right - left)/2;
            if(*mid < *(mid + 1))
                left = mid + 1;
            else 
                right = mid;
        }
        return int(left-arr.begin());
    }
};