// 赎金信
// 关键点: 计数数组/哈希表统计 magazine 字符频次，逐一消耗
// 易错点: 注意 magazine 不足时返回 false
// 日期: 2026.02.04

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vm1(26,0);
        vector<int> vm2(26,0);
        for(auto& e:ransomNote){
            vm1[e-'a']++;
        }
        for(auto& e:magazine){
            vm2[e-'a']++;
        }
        for(int i = 0;i <= 25;i++){
            if(vm1[i] > vm2[i])
                return false;
        }
        return true;
    }
};
