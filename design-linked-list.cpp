class MyLinkedList {
    public:
        /** Initialize your data structure here. */
        struct ListNode {
            int val;
            ListNode *next;
            ListNode *prev;
            ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
        };
        ListNode* fuck;
        MyLinkedList() {
            fuck = nullptr;
        }

        /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
        int get(int index) {
            if(index < 0 || fuck == nullptr)
                return -1;

            ListNode* cur = fuck;
            while(index && cur)
            {
                index--;
                cur = cur->next;
            }
            if(cur)
                return cur->val;
            return -1;
        }

        /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
        void addAtHead(int val) {
            ListNode* cur = new ListNode(val);
            cur->next = fuck;
            fuck = cur;
        }

        /** Append a node of value val to the last element of the linked list. */
        void addAtTail(int val) {
            if(fuck == nullptr)
            {
                fuck = new ListNode(val);
                return;
            }

            ListNode* cur = fuck;
            while(cur->next)
                cur = cur->next;

            cur->next = new ListNode(val);
            cur->next->prev = cur;
        }

        /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
        void addAtIndex(int index, int val) {
            ListNode* cur = fuck;
            ListNode* pre = cur;
            if(index == 0)
            {
                ListNode* cur = new ListNode(val);
                cur->next = fuck;
                if(fuck)
                    fuck->prev = cur;
                fuck = cur;
                return;
            }

            while(index && cur)
            {
                index--;
                pre = cur;
                cur = cur->next;
            }
            if(index == 0 || index == 1)
            {
                ListNode* newNode = new ListNode(val);
                newNode->next = cur;
                pre->next = newNode;
                newNode->prev = pre;
                if(cur)
                    cur->prev = newNode;
            }
        }

        /** Delete the index-th node in the linked list, if the index is valid. */
        void deleteAtIndex(int index) {
            ListNode* cur = fuck;
            ListNode* pre = cur;
            while(index && cur)
            {
                index--;
                pre = cur;
                cur = cur->next;
            }
            if(cur)
            {
                if(pre == cur)
                {
                    fuck = cur->next;
                    if(fuck)
                        fuck->prev = nullptr;
                    delete cur;
                }
                else{
                    pre->next = cur->next;
                    if(cur->next)
                        cur->next->prev = pre;
                    delete cur;
                }
            }

        }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
