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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 0 || head == nullptr)
            return head; 

        ListNode* forwardHead = head;
        ListNode* cur = head;
        ListNode* pre = head;
        while(forwardHead)
        {
            if(n <= 0)
            {
                pre = cur;
                cur = cur->next;
            }
            n--;
            forwardHead = forwardHead->next;
        }

        if(n == 0)
        {
            cur = cur->next;
            delete pre;
            head = cur;
        }
        else if(n < 0)
        {
            pre->next = cur->next;
            delete cur;
        }
        return head; 
    }
};
