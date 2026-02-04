// 四数相加 II
// 关键点: 两两分组哈希表统计和，最后枚举互为相反数的组合
// 易错点: 哈希表存储和的频次，避免重复遍历
// 日期: 2026.02.04

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ret = 0;
        unordered_map<int,int> um1;
        unordered_map<int,int> um2;
        int n = nums1.size();
        for(int i = 0;i <= n - 1;i++){
            for(int j = 0;j <= n - 1;j++){
                um1[nums1[i]+nums2[j]]++;
            }
        }
        for(int i = 0;i <= n - 1;i++){
            for(int j = 0;j <= n - 1;j++){
                um2[nums3[i]+nums4[j]]++;
            }
        }
        for(auto &e1:um1){
            for(auto &e2:um2){
                if(e1.first+e2.first == 0)
                    ret += e1.second * e2.second;
            }
        }
        return ret;
    }
};
