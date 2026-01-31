// 两个数组的交集
// 关键点: 使用 unordered_set 去重并判断存在性
// 易错点: 返回顺序不重要，注意去重
// 日期: 2026.01.31

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        vector<int> ret;
        for(auto & e:s2){
            if(s1.count(e))
                ret.push_back(e);
        }
        return ret;
    }
};
