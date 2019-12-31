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
        ListNode* swapHead = head->next;
        ListNode* tmp = head->next->next;
        ListNode* pre = head;
        head->next->next = head;
        head->next = tmp;
        head = tmp;
        while(head && head->next)
        {
            tmp = head->next->next;
            head->next->next = head;
            pre->next = head->next;
            head->next = tmp;
            pre = head;
            head = tmp;
        }
        return swapHead;
    }
};
