// 反转字符串 II
// 关键点: 每 2k 个字符的前 k 个反转，分段处理
// 易错点: 处理不足 k 或 2k 的结尾区间
// 日期: 2026.02.05

#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        string ret = s;
        int n = s.size();
        for(int i = 0;i <= n - 1;i+= 2*k){
            int left = i;
            int right = i;
            if(n - i > 2 * k){
                right = i + k - 1;
            }
            else if(n - i >= k)
                right = i + k - 1;
            else
                right = n - 1;
            while(left < right){
                    char temp = ret[left];
                    ret[left] = ret[right];
                    ret[right] = temp;
                    left++;
                    right--;
            }
        }
        return ret;
    }
};
