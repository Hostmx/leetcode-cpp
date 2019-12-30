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

    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* cur = head;
            ListNode* pre = head;
            int n = k;
            while(n && cur)
            {
                n--;
                pre = cur;
                cur = cur->next;
            }

            if(n && cur == nullptr)
                return head;

            ListNode* tail = nullptr;
            ListNode* reversedList = nullptr;

            if(n == 0)
            {
                pre->next = nullptr;
                tail = head;
                reversedList = reverseList(head);
            }
            tail->next =  reverseKGroup(cur, k);
            return reversedList;
        }
};
