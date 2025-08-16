class Solution {
public:
    bool isHappy(int n) {
        //此处初始应该就不同，否则后面相等判断难处理
        int slow=n,fast=trans(n);
        while(slow-fast){
            slow=trans(slow);
            fast=trans(trans(fast));
        }
        return slow ==1;
    }
    int trans(int n){
        int ret=0;
        while(n){
            int x=n%10;
            ret+=x*x;
            n/=10;
        }
        return ret;
    }
};