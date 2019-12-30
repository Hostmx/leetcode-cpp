/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
     bool isSymmetricTree(TreeNode* left, TreeNode* right) {
        if((left && !right) || (!left && right))
            return false;
        else if(!left && !right)
            return true;
        else{
            if(left->val != right->val)
                return false;
            if(!isSymmetricTree(left->left, right->right))
                return false;
            if(!isSymmetricTree(left->right, right->left))
                return false;
            return true;
        }
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isSymmetricTree(root->left, root->right);
    }
};
