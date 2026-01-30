// 链表相交
// 关键点: 使用栈从尾部开始比较，找到最后一个相同节点
// 易错点: 1.空链表特判 2.尾节点不同说明无交点 3.栈空时返回对应链表头
// 日期: 2026.01.30

#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)
            return nullptr;
        stack<ListNode*> stackA;
        stack<ListNode*> stackB;
        ListNode * temp = headA;
        while(temp){
            stackA.push(temp);
            temp = temp->next;
        }
        temp = headB;
        while(temp){
            stackB.push(temp);
            temp = temp->next;
        }
        if(stackA.top()==stackB.top()){
            while(!stackA.empty()&&!stackB.empty()){
                ListNode * tempA;
                ListNode * tempB;
                tempA = stackA.top();
                stackA.pop();
                tempB = stackB.top();
                stackB.pop();
                if(tempA != tempB)
                    return tempA->next;
            }
            if(stackA.empty())
                return headA;
            else
                return headB;
        }
        return nullptr;
    }
};
