/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool rec(TreeNode* root) {
        // base cases
        if(!root) return true;
        if(!root->left && !root->right) return true;
        // check the left subtree is true
        if(root->left) {
            if(!rec(root->left)) return false;
            if(root->val != root->left->val) return false;
        }
        if(root->right) {
            if(!rec(root->right)) return false;
            if(root->val != root->right->val) return false;
        }
        
        return true;
        //check right is true
        //check current equal left equal right values
    }
    bool isUnivalTree(TreeNode* root) {
        return rec(root);
    }
};