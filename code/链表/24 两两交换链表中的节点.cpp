// 两两交换链表中的节点
// 关键点: 使用虚拟头节点，每次处理相邻两个节点的交换
// 易错点: 指针交换顺序要正确，先保存再修改
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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode* dumpty_head = new ListNode(0,head);
        ListNode* left = nullptr,*right = dumpty_head;
        while(right->next&&right->next->next){
            left = right->next;
            right ->next = left -> next;
            left->next = right -> next->next;
            right ->next ->next= left;
            left = right->next;
            right = left->next;
        }
        return dumpty_head->next;
    }
};
