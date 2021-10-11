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
    int rec(int& diam, TreeNode* root ) {
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        int left = 0; int right = 0;
        if(root->left) {
            left = 1 + rec(diam, root->left);
        }
        if (root->right) {
            right =  1 + rec(diam, root->right);
        }
        // update the diamter
        // return the depth
        diam = max(diam, right + left);
        return max(left, right);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diam = 0;
        rec(diam, root);
        return diam;
        
    }
};