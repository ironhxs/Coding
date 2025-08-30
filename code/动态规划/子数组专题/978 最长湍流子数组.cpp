// 978 最长湍流子数组
// 关键点: 大小关系编码，相邻关系交替变化
// 易错点: 处理相等元素和边界情况
// 日期: 2025.08.30

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        //大小关系编码
        vector<int> cmp(n,0);
        for(int i = 1;i < n;i++){
            cmp[i] = arr[i - 1] < arr[i];
            if(arr[i - 1] == arr[i])
                cmp[i] = INT_MAX;
        }
        vector<int> dp(n + 1,1);
        for(int i = 1;i < n;i++){
            if(cmp[i - 1] - cmp[i] == 1||cmp[i - 1] - cmp[i] == -1)
                dp[i] = dp[i - 1] + 1;
            else if(cmp[i - 1] - cmp[i] == 0 && cmp[i] != INT_MAX)
                dp[i] = 2;
            else if(cmp[i - 1] == INT_MAX && cmp[i] != INT_MAX)
                dp[i] = 2;
        }
        return *max_element(dp.begin(),dp.end());
    }
};
