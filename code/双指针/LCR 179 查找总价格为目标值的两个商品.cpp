# include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        auto left = price.begin();
        auto right = price.end()-1;
        while(right-left){
            if(*left+*right>target)
                right--;
            else if(*left+*right<target)
                left++;
            else
                return vector<int>{*left,*right};
        } 
        return vector<int>{};
    }
};