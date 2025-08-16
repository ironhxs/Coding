# include <vector>
using namespace std;
//(right-left++)**right
//此处++运算优先级高，所以转化为(right-(left++))即(right-(left+1))
class Solution {
public:
    int maxArea(vector<int>& height) {
        auto left=height.begin();
        auto right=height.end()-1;
        int max=0;
        while(right-left){
            int temp=0;
            if(*left<=*right){
                temp=(right-left)**left;
                left++;
            }
                
            else{
                temp=(right-left)**right;
                right--;
            }
                
            max=temp>max?temp:max;
        }
        return max;
    }
};