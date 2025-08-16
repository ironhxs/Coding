# include <vector>
# include <algorithm>
using namespace std;
//类上面三数之和，相当于拓展版
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        for(auto largest = nums.end()-1;largest>nums.begin()+2;largest--){
            if(largest!=nums.end()-1 && *largest==*(largest+1))
                continue;
            for(auto larger = largest -1;larger > nums.begin()+1; larger--){
                if(larger!=largest-1&&*larger==*(larger+1))
                    continue;
                auto left = nums.begin(),right = larger-1;
                while(left<right){
                    //1. 多个数相加会导致溢出
                    //2. 多条件判断，这样可以提高性能
                    //3. 由于原始右边均为int需要强转才可以将右值转换为long long
                    long long sum = (long long)*left-target+*right+*larger+*largest ;
                    if(sum < 0)
                        left++;
                    else if(sum > 0)
                        right--;
                    else{
                        ret.push_back({*left,*right,*larger,*largest});
                        ++left;
                        --right;
                        while(left<right && *left==*(left-1))
                            left++;
                        while(left<right && *right==*(right+1))
                            right--;
                    } 
                }
            }
        }
        return ret;
    }
};