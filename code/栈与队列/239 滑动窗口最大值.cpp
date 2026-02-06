// 滑动窗口最大值
// 关键点: 单调递减队列，维护窗口内可能成为最大值的元素
// 易错点: pop 时仅当队首等于滑出元素时才弹出
// 日期: 2026.02.06

#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret;
        for(int i = 0;i <= n - 1;i++){
            push(nums[i]);
            if(i > k - 1)
                pop(nums[i - k]);
            if(i >= k - 1)
                ret.push_back(dq.front());
        }
        return ret;
    }
private:
    deque<int> dq;
    void push(int a){
        while(!dq.empty()&&a > dq.back()){
            dq.pop_back();
        }
        dq.push_back(a);
    }
    void pop(int a){
        if(a == dq.front())
            dq.pop_front();
    }
};
