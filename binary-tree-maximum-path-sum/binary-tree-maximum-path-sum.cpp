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
    int max_value = INT_MIN;
    int helper(TreeNode* root) {
        if(!root) return 0;
        int max_l = max(0, helper(root->left));
        int max_r = max(0, helper(root->right));
        max_value = max(max_value, max_l + max_r + root->val);
        return max(max_l,max_r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return max_value;
    }
};