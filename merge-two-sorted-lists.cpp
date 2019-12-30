
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tmp = nullptr;
        while(l1 || l2)
        {
            if(l2 == nullptr)
            {
                if(head == nullptr)
                {
                    head = new ListNode(l1->val);
                    tmp = head;
                }
                else
                {
                    ListNode* newNode =  new ListNode(l1->val);
                    tmp->next = newNode;
                    tmp =  newNode;
                }
                l1 = l1->next;
                continue;
            }

            if(l1 == nullptr)
            {
                if(head == nullptr)
                {
                    head = new ListNode(l2->val);
                    tmp = head;
                }
                else
                {
                    ListNode* newNode =  new ListNode(l2->val);
                    tmp->next = newNode;
                    tmp =  newNode;
                }
                l2 = l2->next;
                continue;
            }


            int val = 0;
            if(l1->val < l2->val)
            {
                val = l1->val;
                l1 = l1->next;
            }
            else 
            {
                val = l2->val;
                l2 = l2->next;
            }
                
            if(head == nullptr){
                head = new ListNode(val);
                tmp = head;
            }
            else{
                ListNode* newNode =  new ListNode(val);
                tmp->next = newNode;
                tmp = newNode;
            }
        }

        
        return head;
    }
};
