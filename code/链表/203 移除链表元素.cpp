// 移除链表元素
// 关键点: 使用虚拟头节点统一处理，避免头节点特殊处理
// 易错点: 1.要先存要删除的节点再释放 2.只有不删下一个节点时才移动指针
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* Head = new ListNode(0,head);
        ListNode* temp = Head;
        while(temp -> next){
            if(temp->next->val == val){
                //1.注意要先存要删除的
                ListNode* delete_node = temp->next;
                temp->next = temp->next->next;
                delete delete_node;
            }
            else
                //只有不删下一个,才移动
                temp = temp->next;
        }
        return Head->next;
    }
};
