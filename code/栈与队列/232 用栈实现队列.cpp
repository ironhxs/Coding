// 用栈实现队列
// 关键点: 双栈模拟，输入栈和输出栈，输出栈空时才倒入
// 易错点: pop/peek 时需先检查 sout 是否为空
// 日期: 2026.02.05

#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue(){
        
    }
    
    void push(int x) {
        sin.push(x);
    }
    
    int pop() {
        if(sout.empty())
            while(!sin.empty()){
                int temp = sin.top();
                sin.pop();
                sout.push(temp);
            }
        int temp = sout.top();
        sout.pop();
        return temp;
    }
    
    int peek() {
        if(sout.empty())
            while(!sin.empty()){
                int temp = sin.top();
                sin.pop();
                sout.push(temp);
            }
        int temp = sout.top();
        return temp;
    }
    
    bool empty() {
        return(sin.empty()&&sout.empty());
    }
private:
    stack<int> sin;
    stack<int> sout;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
