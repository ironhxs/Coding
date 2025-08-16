# include <iostream>
# include <vector>
using namespace std;
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         //size
//         auto left=nums.begin();
//         auto right=nums.begin();
//         while(1)
//             {
//                 //从前往后寻找第一个0
//                 while(left<nums.end()-1 &&*left!=0)
//                     left++;
//                 if(left==nums.end()-1&&*left)
//                     break;
//                 if(left>right)
//                     right=left;
//                 //往后寻找第一个非0
//                 while(right<nums.end()-1&&*right==0)
//                     right++;
//                 if(right==nums.end()-1&&*right==0)
//                     break;
//                 //符合要求交换位置
//                 if(*left==0&&*right!=0)
//                 {
//                     swap(*left,*right);
//                     left++;
//                 }
//             }
//     }
// };
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int des=-1,cur=0;cur<n;++cur)
          if(nums[cur]) swap(nums[++des],nums[cur]);
    }
};