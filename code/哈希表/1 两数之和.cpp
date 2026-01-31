// 两数之和
// 关键点: 哈希表可在一次遍历中记录已遍历元素并检查补数（更优实现）
// 本实现基于题主提供的暴力构建和哈希记录和到下标对的做法
// 易错点: 本实现为 O(n^2) 构建，注意可优化为 O(n)
// 日期: 2026.01.31

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,pair<int,int>> um;
        int n = nums.size();
        for(int i =0;i <= n - 1;i++){
            for(int j = i + 1;j <= n - 1;j++){
                int _sum = nums[i] + nums[j];
                um[_sum] = {i,j};
            }
        }
        return vector<int>{um[target].first,um[target].second};
    }
};
