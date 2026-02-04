// 反转字符串
// 关键点: 双指针交换，原地反转
// 易错点: 注意 left < right
// 日期: 2026.02.05

#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};
