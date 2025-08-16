// 最小覆盖子串
// 关键点: 双哈希表记录需要的字符频次和窗口中的字符频次
// 易错点: t中相同字符也应该放进去，需要另外一个hash存储，这是个极大的易混淆的点
// 日期: 2025.08.05

# include <string>
# include <set>
# include <algorithm>
using namespace std;

//算法1: 滑动窗口（双哈希表）
class Solution { 
public:
    string minWindow(string s, string t) {
        int cnt = 0;
        set<char>_set(t.begin(),t.end());
        const int target = _set.size();
        //数组同基本类型，局部是垃圾值初始化
        int hash[128]{};
        //t中相同也应该放进去，所以也需要另外一个来hash存储，这是个极大的易混淆的点
        int hash2[128]{};
        for(const auto& e:t)
            hash2[e]++;
        auto left_temp=s.begin(),right_temp=s.end();
        for(auto left = s.begin(),right = left;right < s.end();right++){
            // if(t.find(*right)&&hash[*right]==0)
            //find找不到的时候返回的是npos一个很大的数非0，string没有count方法
            if(hash[*right]==hash2[*right]-1)
                cnt++;
            hash[*right]++;
            while(hash[*left] > hash2[*left]){
                hash[*left]--;
                left++;
            } 
            if(cnt==target&&(right-left +1 < right_temp - left_temp)){
                    right_temp = right+1;
                    left_temp = left;
                }
        }
        if(cnt!=target)
            return "";
        else
            return string(left_temp,right_temp);
    }
};
