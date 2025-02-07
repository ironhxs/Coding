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
      - 边界更新：应为mid+/-1，否则容易死循环且搜索重复(mid)，如下：
        >数组`[2, 5]`，查找`5`。
        >
        >初始：`l=0`, `r=1`, `mid=0`. `nums[0]=2 < 5`，所以`l=0`。
        >
        >下一轮：`l=0`, `r=1`, `mid=0`。再次相同，无限循环。
