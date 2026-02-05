// 用队列实现栈
// 关键点: 双队列模拟，每次 pop/top 需将前 n-1 个元素移到另一个队列
// 易错点: top 操作后需把元素放回
// 日期: 2026.02.05

#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int n = q1.size();
        int cnt = n - 1;
        while(cnt--){
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        int ret = q1.front();
        q1.pop();
        while(!q2.empty()){
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
        return ret;
    }
    
    int top() {
        //不可直接用back
        int n = q1.size();
        int cnt = n - 1;
        while(cnt--){
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        int ret = q1.front();
        q1.pop();
        q2.push(ret);
        while(!q2.empty()){
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
        return ret;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
   queue<int> q1;
   queue<int> q2; 
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
