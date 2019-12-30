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
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == nullptr || head->next == nullptr)return head;
            ListNode* tmp = head;
            ListNode* tailor = tmp;
            int listLen = 0;
            while(tmp)
            {
                listLen++;
                tailor = tmp;
                tmp = tmp->next;
            }
            k = k % listLen;
            if(k == 0)
                return head;
            tmp = head;
            ListNode* cur = head;
            ListNode* pre = head;
            while(tmp)
            {
                if(k <= 0)
                {
                    pre = cur;
                    cur = cur->next;
                }
                k--;
                tmp = tmp->next;
            }

            pre->next = nullptr;
            tailor->next = head;
            head = cur;

            return head;
        }
};
