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
    int rec(TreeNode* root, int level, int target, int& parent) {
        if(!root) return 0;
        if(root->val == target) return level;
        parent = root->val;
        int l = rec(root->left, level + 1, target, parent);
        if(l != 0) return l;
        parent = root->val;
        l = rec(root->right, level + 1, target, parent);
        if(l != 0) return l;
        return 0;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int xparent = -1;
        int xlevel = 0;
        int yparent = -1;
        int ylevel = 0;
        xlevel = rec(root, 0, x, xparent);
        // cout <<"xlevel is " << xlevel << " and xparent is " << xparent << "\n";
        ylevel = rec(root, 0, y, yparent);
        // cout <<"ylevel is " << ylevel << " and yparent is " << yparent << "\n";
        if(xparent != yparent && xlevel == ylevel) return true;
        return false;
        
    }
};