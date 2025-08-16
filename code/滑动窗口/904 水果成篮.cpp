// 水果成篮
// 关键点: 滑动窗口维护最多两种水果的最长子数组
// 易错点: 局部变量没有默认初始值，全是垃圾值！
// 日期: 2025.08.05

# include <vector>
# include <unordered_map>
# include <algorithm>
using namespace std;

//算法1: 滑动窗口
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>hash;
        //局部变量没有默认初始值，全是垃圾值！
        int length=0,kind=0;
        for(auto left = fruits.begin(),right = left;right < fruits.end();right++){
            if(hash[*right]==0)
               kind++;
            hash[*right]++;
            while(kind>2)
            {
                hash[*left]--;
                if(!hash[*left])
                    kind--;
                left++;
            }
            length = max(length,(int)(right - left +1));
        }
        return length;
    }
};
