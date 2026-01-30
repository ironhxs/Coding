// 删除链表的倒数第N个节点
// 关键点: 递归法，回溯时计数，到达目标位置时删除
// 易错点: 1.递归返回时要正确处理删除节点 2.使用引用传递计数和完成标志
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
    ListNode* _removeNthFromEnd(ListNode* head, int& n,int& count,bool& finish) {
        if(head->next){
            ListNode* next = _removeNthFromEnd(head->next,n,count,finish);
            if(finish){
                delete head->next;
                head->next = next;
                finish = false;
            }
            count++;
            if(count == n){
                finish = true;
                head = head ->next;
            }
        }
        else{
            count = 1;
            if(count == n){
                finish = true;
                head = head ->next;
            }
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return nullptr;
        int count = 0;
        bool finish = false;
        return _removeNthFromEnd(head,n,count,finish);
    }
};
