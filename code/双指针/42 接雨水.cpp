# include<vector>
using namespace std;
//首先认识到一点：每个位置i能装的水是,min{max{i左边},max{i右边}}
//借鉴高中数学的放缩思想，可以采用双指针
class Solution {
public:
    int trap(vector<int>& height) {
        auto left = height.begin(),right = height.end()-1;
        int ret = 0 , left_max = 0,right_max = 0;
        //搞清楚相遇到底可不可以！其实是可以的，因为指针指的是还没有处理的，所以相遇的应该要处理
        while(left <= right){
            if(left_max < right_max){
                //ret+=(left_max-*left)>0?(left_max-*left):0;
                //注意+=的运算级高于三目运算符，应该加括号
                ret+=((left_max-*left)>0?(left_max-*left):0);
                if(*left > left_max)
                    left_max = *left;
                left++;
            }
            else{
                ret+=((right_max-*right)>0?(right_max-*right):0);
                if(*right > right_max)
                    right_max = *right;
                right--;
            }
        }
        return ret;
    }
};