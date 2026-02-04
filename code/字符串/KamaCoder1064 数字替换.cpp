// 数字替换（KamaCoder 1064）
// 关键点: 扩容+逆序遍历+原地替换
// 易错点: 逆序处理避免覆盖，resize 后下标变化
// 日期: 2026.02.05

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int cnt = 0;
    for(auto& e : s)
        if(isdigit(e))
            cnt += 5;
    int n = s.size();
    s.resize(n + cnt);
    int left = n - 1;
    int right = n - 1 + cnt;
    while(left >= 0){
        char temp = s[left--];
        if(isdigit(temp)){
            s[right--] = 'r';
            s[right--] = 'e';
            s[right--] = 'b';
            s[right--] = 'm';
            s[right--] = 'u';
            s[right--] = 'n';
        }
        else
            s[right--] = temp;
    }
    cout<<s;
    return 0;
}
