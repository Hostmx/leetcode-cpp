/**
 ,* Definition for a binary tree node.
 ,* struct TreeNode {
 ,*     int val;
 ,*     TreeNode *left;
 ,*     TreeNode *right;
 ,*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ,* };
 ,*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p && !q) || (!p && q))
            return false;
        else if(!p && !q)
            return true;
        else{
            if(p->val != q->val)
                return false;
            if(!isSameTree(p->left, q->left))
                return false;
            if(!isSameTree(p->right, q->right))
                return false;
            return true;
        }
    }
};
