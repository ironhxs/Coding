# include <vector>
using namespace std;
//新理解：单调性可以抽象为（任意mid满足一个条件可以推出left/right一定满足这个条件）的条件
//找山峰问题的变形
//画图可以发现：满足的一个“单调性”是与尾数之间的大小关系
class Solution {
public:
    int findMin(vector<int>& nums) {
        auto left = nums.begin(),right = nums.end()-1;
        while(left < right){
            auto mid = left + (right - left)/2;
            if(*mid > *(nums.end()-1))
                left = mid + 1;
            else 
                right = mid;
        }
        return *left;
    }
};