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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = nullptr;
    ListNode *tmp = nullptr;
    if (l1 == nullptr && l2 == nullptr)
      return nullptr;
    else if (l1 && l2 == nullptr)
      return l1;
    else if (l1 == nullptr && l2)
      return l2;
    else {
      if (l1->val < l2->val) {
        head = l1;
        tmp = l1;
        l1 = l1->next;
      } else {
        head = l2;
        tmp = l2;
        l2 = l2->next;
      }
    }

    while (l1 && l2) {
      if (l1->val < l2->val) {
        tmp->next = l1;
        tmp = tmp->next;
        l1 = l1->next;
      } else {
        tmp->next = l2;
        tmp = tmp->next;
        l2 = l2->next;
      }
    }

    tmp->next = l1 ? l1 : l2;

    return head;
  }

  ListNode *mergeSortList(ListNode *head) {
    if (head->next == nullptr)
      return head;
    ListNode *l = nullptr;
    ListNode *h = nullptr;
    partitionList(head, l, h);
    l = mergeSortList(l);
    h = mergeSortList(h);
    return mergeTwoLists(l, h);
  }

  void partitionList(ListNode *head, ListNode *&l, ListNode *&h) {
    l = head;
    h = head;
    ListNode *prev = h;
    while (head && head->next) {
      prev = h;
      h = h->next;
      head = head->next->next;
    }
    prev->next = nullptr;
  }

public:
  ListNode *sortList(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    return mergeSortList(head);
  }
};
