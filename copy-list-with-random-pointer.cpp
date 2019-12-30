/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* copyHead = nullptr;
        Node* tmp = nullptr;
        std::unordered_map<Node*, Node*> copyMap;
        while(head)
        {
            if(copyMap.find(head) == copyMap.end())
            {
                tmp = new Node(head->val);
                copyMap[head] = tmp;
            }

            if(!copyHead)
                copyHead = copyMap[head];
            if(head->random)
            {
                if(copyMap.find(head->random) == copyMap.end())
                {
                    tmp->random = new Node(head->random->val);
                    copyMap[head->random] = tmp->random;
                }
                else
                    tmp->random = copyMap[head->random];
            }

            if(head->next)
            {
                if(copyMap.find(head->next) == copyMap.end())
                {
                    tmp->next = new Node(head->next->val);
                    copyMap[head->next] = tmp->next;
                }
                else
                    tmp->next = copyMap[head->next];
            }
            tmp = tmp->next;
            head = head->next;
        }
        return copyHead;
    }
};
