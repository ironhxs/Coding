// 环形链表 II
// 关键点: 使用哈希集合记录访问过的节点，重复访问即为环入口
// 易错点: 空链表和单节点无环特判
// 日期: 2026.01.30

#include <set>
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
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)
            return nullptr;
        bool hav = false;
        ListNode * slow = head;
        set<ListNode *> s;
        while(slow){
            if(!s.insert(slow).second)
                return slow;
            slow = slow->next;
        }
        return nullptr;
    }
};
