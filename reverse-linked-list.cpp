/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
     ListNode* reverseList(ListNode* head, ListNode*& reverseHead) {
         if(head == nullptr)
             return reverseHead;
        ListNode* orgNext = nullptr;
        orgNext = head->next;
        head->next = reverseHead;
        reverseHead = head;
        head = orgNext;
        return reverseList(head, reverseHead);
    }
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* reverseHead = nullptr;
        return reverseList(head, reverseHead);
    }
};
