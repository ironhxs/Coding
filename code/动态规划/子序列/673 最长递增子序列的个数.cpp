// 673 最长递增子序列的个数
// 关键点: 需要维护两个数组：长度数组和个数数组
// 易错点: 当长度相等时累加个数，当长度更长时继承个数
// 日期: 2025.08.31

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        //以元素i结尾的最长满足条件子序列长度
        vector<int> len(n,1);
        //以元素i结尾的最长满足条件子序列的路径个数
        vector<int> count(n,1);
        int _max = 1,cnt = 1;
        for(int i = 1;i < n;i++){
            for(int j = i - 1;j >= 0;j--){
                if(nums[j] < nums[i]){
                    if(len[j] + 1 == len[i])
                        count[i] += count[j];
                    else if(len[j] + 1 > len[i])
                        count[i] = count[j];
                    len[i] = max(len[i],len[j] + 1);
                }
            }
            if(len[i] > _max){
                _max = len[i];
                cnt = count[i];
            }
            else if(len[i] == _max)
                cnt += count[i];
        }
        return cnt;
    }
};
