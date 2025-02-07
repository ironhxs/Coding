# Coding
刷leetcode的记录，聊以自慰。
>使用的是leedcode配合某刷题单。
>积累cpp语法是通过[cpp参考站](https://legacy.cplusplus.com/reference/)
1. 数组
  - 704 二分查找
    1. cpp基础
      - [std::vector::size()](https://legacy.cplusplus.com/reference/vector/vector/size/)
    2. 编程bug
      - while(1)***;***
    3. 算法bug
      - 退出条件：应为l>=r,若仅为==的话，会出现死循环，且有越界风险。
        - >数组是[1,3,5]，target是2。
          >
          >初始left=0，right=2，mid=1，nums[1]=3>2，所以right=0。
          >
          >进入下一轮循环，mid=0，nums[0]=1<2，left=1。此时left=1，right=0，循环继续？因为do-while(1)是无限循环，所以会继续执行。
          >
          >此时mid=(1+0)/2=0，再次检查nums[0]，然后根据比较调整边界，但此时left=1，right=0，导致mid=0，之后进入无限循环。
        >
        - >nums = [5], target = 3
          >第一次循环mid=0，nums[0]=5>3，所以r=mid-1=-1。此时l=0，r=-1。
          >
          >进入下一次循环，mid=(0 + (-1))/2=0。检查nums[mid]=5，仍然大于3，所以r=mid-1=-1-1=-2。此时l=0, r=-2。
          >
          >再次循环，mid=(0 + (-2))/2 = -1，但访问nums[-1]会导致越界，程序崩溃。
      - 边界更新：应为mid+/-1，否则容易死循环且搜索重复(mid)，如下：
        >数组`[2, 5]`，查找`5`。
        >
        >初始：`l=0`, `r=1`, `mid=0`. `nums[0]=2 < 5`，所以`l=0`。
        >
        >下一轮：`l=0`, `r=1`, `mid=0`。再次相同，无限循环。
    4. 算法优化
        1. 空数组，导致越界。
           ```cpp
           if(nums.empty()) return -1;
           ```
        3. 整数溢出
          >当left和right都很大时，相加可能会超出int的范围。
          ``` cpp
          mid = left + (right - left)/2;
          ```
    5. 完整代码：
       ```cpp
         int search(vector<int>& nums, int target) {
            int len=nums.size();
            int l=0;
            int r=len-1;
            int mid;
            do
            {
                mid=(l+r)/2;
                if(nums[mid]==target)
                    return mid;
                else if(l>=r)
                    return -1;
                else if(nums[mid]<target)
                    l=mid+1;
                else if(nums[mid]>target)
                    r=mid-1;
            }while(1);
        }
       ```
