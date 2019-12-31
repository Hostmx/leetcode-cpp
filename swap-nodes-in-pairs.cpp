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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* pre = head;
        ListNode* cur = head;
        while(cur && cur->next)
        {
            int val = cur->next->val;
            cur->next->val = cur->val;
            cur->val = val;
            cur = cur->next->next;
        }
        return head;
    }
};
