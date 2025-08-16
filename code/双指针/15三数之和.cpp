# include <vector>
# include <algorithm>
using namespace std;
//几乎与构成三角形相同
//前后指针类似于给树剪枝
//精确解在两指针之间还有！
//--慎用！！！
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret{};
        sort(nums.begin(),nums.end());
        for(auto large = nums.end()-1;large>nums.begin()+1;--large){
            //一直报超内存，优化一下
            if(*large<0)
                break;
            // auto temp = *large;
            // if(--large>nums.begin()+1&&temp==*large)
            //     continue;
            //线性结构找前面那个非常容易不需要存储
            if(large<nums.end()-1&&*(large+1)==*large)
                continue;
            auto left = nums.begin(),right = large-1;
            while(right > left){
                if(*left+*right+*large>0)
                    right--;
                else if(*left+*right+*large<0)
                    left++;
                else{
                    ret.push_back({*left,*right,*large});
                    //这一定要先移动再判重，否则若不重复他就不移动呀，就加相同的了（会报超内存的错误）
                    left++;
                    right--;
                    //right-left有问题！因为前面同时+和-，就有可能已经<了，就不会触发这个
                    while((right>left)&&*right==*(right+1))
                        right--;
                    while((right>left)&&*left==*(left-1))
                        left++;
                }
            } 
        }
        return ret;  
    }
};