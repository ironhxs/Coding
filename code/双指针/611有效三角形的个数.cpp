# include <vector>
# include <algorithm>
using namespace std;
//三条边：双指针只能只能遍历两条，可以考虑利用单调性固定一条最长的
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ret = 0;
        sort(nums.begin(),nums.end());
        auto longest = nums.end()-1;
        for(;longest>nums.begin()+1;longest--){
            auto left = nums.begin();
            auto right = longest-1;
            while(right-left){
                if(*left+*right<=*longest)
                    left++;
                else{
                    ret += static_cast<int>(right - left);
                    right--;
                    //不用重新刷新了，因为*right已经是减小了，*left再减小不可能符合
                    //left = nums.begin();
                }
            }
        }
        return ret;
    }
};