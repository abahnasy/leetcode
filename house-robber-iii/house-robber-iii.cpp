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
    void dfs(TreeNode* root, int& with_root, int& without_root) {
        if(!root) {
            with_root = 0;
            without_root = 0;
            return;
        }
        if(!root->left && !root->right) {
            with_root = root->val;
            without_root = 0;
            return;
        }
        int left_with_root = 0;
        int left_without_root = 0;
        int right_with_root = 0;
        int right_without_root = 0;
        dfs(root->left, left_with_root, left_without_root);
        dfs(root->right, right_with_root, right_without_root);
        
        with_root = root->val + left_without_root + right_without_root;
        without_root = max(left_with_root, left_without_root) + max(right_with_root, right_without_root);
        
        return;
    }
    int rob(TreeNode* root) {
        int with_root = 0;
        int without_root = 0;
        dfs(root, with_root, without_root);
        return max(with_root, without_root);
    }
};