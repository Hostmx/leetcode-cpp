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
        ListNode* reverseList(ListNode* head, int& len) {
            ListNode* reverseHead = nullptr;
            ListNode* orgNext = nullptr;
            while(head){
                len++;
                orgNext = head->next;
                head->next = reverseHead;
                reverseHead = head;
                head = orgNext;
            }
            return reverseHead;
        }

    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if(headA == nullptr || headB == nullptr)
                return nullptr;
            int lenA = 0;
            int lenAB = 0;
            int lenB = 0;
            ListNode* orgA = headA;
            ListNode* reverseA = reverseList(headA, lenA);
            ListNode* reverseB = reverseList(headB, lenAB);
            if(reverseB != orgA)
            {
                reverseList(reverseA, lenA);
                reverseList(reverseB, lenAB);
                return nullptr;
            }
            ListNode* reverseAA = reverseList(reverseA, lenB);
            int len = (lenA + lenAB - lenB + 1)/2;
            while(len > 1)
            {
               len--;
               orgA = orgA->next;
            }
            return orgA;
        }
};
