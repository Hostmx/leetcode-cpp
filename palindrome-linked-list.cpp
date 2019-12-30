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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return true;

        ListNode* reverseHead = nullptr;
        ListNode* orgNext = nullptr;
        ListNode* tmp = head;
        while(tmp && tmp->next)
        {
            tmp = tmp->next->next;
            orgNext = head->next;
            head->next = reverseHead;
            reverseHead = head;
            head = orgNext;
        }
        if(tmp)
            head = head->next;
        while(reverseHead && head)
        {
            if(head->val != reverseHead->val)
                return false;
            head = head->next;
            reverseHead = reverseHead->next;
        }
        return true;
    }
};
