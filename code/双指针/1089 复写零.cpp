# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
         auto cur = arr.begin();
         auto des = arr.begin()-1;
        //先占满坑
        for(;des<arr.end()-1;cur++){
            if(!*cur)
                des+=2;
            else
                des++;
        }
        //多走了一步（for中二三部分不一致容易忽视）
        cur--;
        //填坑
        for(;cur>=arr.begin();cur--){
            //可能最后一次占的两个0的坑，去一个0
            if(des-arr.end()==0){
                des=arr.end()-1;
                *(des--)=0;
            }
            else{
                *(des--)=*cur;
                if (!*cur)
                    *(des--)=0;
            }        
        }
    }
};