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
        if(lists.empty())
            return nullptr;
        ListNode* mergedList = nullptr;
        ListNode* mergedListHead = nullptr;
        ListNode* firstSortedList = lists.back();;
        lists.pop_back();
        while(firstSortedList)
        {
            if(mergedListHead == nullptr)
            {
                mergedListHead = firstSortedList;
                mergedList = firstSortedList;
                firstSortedList = firstSortedList->next;
                continue;
            }
            mergedList->next = firstSortedList;
            mergedList = mergedList->next;
            firstSortedList = firstSortedList->next;
        }
        while(!lists.empty())
        {
            ListNode* sortedList = lists.back();;
            lists.pop_back();
            mergedListHead = mergeTwoLists(mergedListHead, sortedList);
        }
        return mergedListHead;
    }
};
