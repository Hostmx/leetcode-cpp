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
        ListNode* mergeLists(vector<ListNode*>& listNodes, int low, int high)
        {
            if (low == high) return NULL;
            if (high - low == 1) return listNodes[low];
            if (high - low == 2) return mergeTwoLists(listNodes[low], listNodes[high - 1]);
            int mid = (high + low) / 2;
            ListNode* a = mergeLists(listNodes, low, mid);
            ListNode* b = mergeLists(listNodes, mid, high);
            return mergeTwoLists(a, b);
        }

        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* head = nullptr;
            ListNode* tmp = nullptr;
            if(l1 == nullptr && l2 == nullptr)
                return nullptr;
            else if(l1 && l2 == nullptr)
                return l1;
            else if(l1 == nullptr && l2)
                return l2;
            else
            {
                if(l1->val < l2->val)
                {
                    head = l1;
                    tmp = l1;
                    l1 = l1->next;
                }
                else
                {
                    head = l2;
                    tmp = l2;
                    l2 = l2->next;
                }

            }


            while(l1 && l2)
            {
                if(l1->val < l2->val)
                {
                    tmp->next = l1;
                    tmp = tmp->next;
                    l1 = l1->next;
                }
                else
                {
                    tmp->next = l2;
                    tmp = tmp->next;
                    l2 = l2->next;
                }
            }

            tmp->next = l1 ? l1:l2;

            return head;
        }
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            return mergeLists(lists, 0, lists.size());
        }
};
