// 反转链表
// 关键点: 递归法，先递归到末尾，回溯时反转指针方向
// 易错点: 1.空链表特判 2.递归返回后原头节点的next要置空
// 日期: 2026.01.30

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* _reverseList(ListNode* head) {
        if(head->next){
            ListNode* end = _reverseList(head->next);
            head->next->next = head; 
            return end;
        }
        else
            return head;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode* Head = head;
        ListNode* ret = _reverseList(head);
        Head->next = nullptr;
        return ret;
    }
};
