// 字符串循环右移（KamaCoder 1065）
// 关键点: 三次反转法，先整体反转再分段反转
// 易错点: k 可能为 0 或等于长度
// 日期: 2026.02.05

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int k;
    cin >> k;
    cin >> s;
    auto _reverse = [&](int left,int right){
        while(left < right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    };
    int n = s.size();
    _reverse(0,n - 1);
    _reverse(0,k - 1);
    _reverse(k,n - 1);
    cout<<s;
    return 0;
}
