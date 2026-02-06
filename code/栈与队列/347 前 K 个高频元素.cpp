// 前 K 个高频元素
// 关键点: 哈希表统计频次 + 小顶堆维护前 K 大
// 易错点: 小顶堆需要自定义比较器，堆大小超过 k 时弹出
// 日期: 2026.02.06

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret(k);
        unordered_map <int,int> um;
        auto cmp = [](pair<int,int> left,pair<int,int> right){
            return left.second > right.second; 
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq;
        for(auto& e:nums){
            um[e]++;
        }
        for(auto& e:um){
            pq.push(e);
            if(pq.size() > k)
                pq.pop();
        }
        for(int i = 0;i <= k - 1;i++){
            ret[i]=pq.top().first;
            pq.pop();
        }
        return ret;
    }
};
