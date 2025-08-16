# include <vector>
using namespace std;
class Solution {
public:
    int takeAttendance(vector<int>& records) {
        auto left = records.begin(),right = records.end()-1;
        while(left < right){
            auto mid = left + (right - left)/2;
            if(*mid == int(mid- records.begin()))
                left = mid + 1;
            else
                right = mid;
        }
        //上面可以找到第一个不满足条件的，下一个位置的编号即为缺席的同学的学号
        //return int(left - records.begin());
        //题意是一定有一个缺席，所以到这里的还有可能是最后一个没到
        return ((*left == int(left- records.begin()))?records.size():int(left - records.begin()));
    }
};