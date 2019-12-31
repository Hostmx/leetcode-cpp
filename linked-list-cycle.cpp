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
    bool hasCycle(ListNode *head) {

        ListNode* tmp = head;
        ListNode* tmp2 = head;
        while(tmp2)
        {
            tmp2 = tmp2->next;
            if(tmp2 != nullptr && tmp2 == tmp)
                return true;
            tmp2 = tmp2->next;
            if(tmp2 != nullptr && tmp2 == tmp)
                return true;
            tmp = tmp->next;
        }
        return false;
    }
};
