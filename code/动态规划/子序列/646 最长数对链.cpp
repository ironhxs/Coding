// 646 最长数对链
// 关键点: 类似于最长递增子序列，先按first排序
// 易错点: 函数定义必须要有{}，类内调用要static
// 日期: 2025.08.31

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //函数定义必须要有{}，类内调用要static
    static bool cmp(vector<int>& l,vector<int>& r){
        return l[0] < r[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        //类似于最长递增子序列
        //按照first排序,希望怎样排序就传入什么为true的比较函数
        sort(pairs.begin(),pairs.end(),cmp);
        int n = pairs.size();
        vector<int> dp(n,1);
        for(int i = 1;i < n;i++){
            for(int j = i - 1;j >= 0;j--){
                if(pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
