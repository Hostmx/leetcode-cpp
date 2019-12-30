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
    ListNode* reverseList(ListNode* head) {
        ListNode* reverseHead = nullptr;
        ListNode* orgNext = nullptr;
        while(head){
            orgNext = head->next;
            head->next = reverseHead;
            reverseHead = head;
            head = orgNext;
        }
        return reverseHead;
    }
};
