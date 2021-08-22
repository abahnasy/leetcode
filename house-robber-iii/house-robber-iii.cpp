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
    pair<int, int> dfs(TreeNode* root) {
        if(!root) {
            return {0, 0};
        }
        if(!root->left && !root->right) {
            return {root->val, 0};
        }
        int left_with_root = 0;
        int left_without_root = 0;
        int right_with_root = 0;
        int right_without_root = 0;
        pair<int, int> l_tree = dfs(root->left);
        pair<int, int> r_tree = dfs(root->right);
        
        return {
            root->val + l_tree.second + r_tree.second, 
            max(l_tree.first, l_tree.second) + max(r_tree.first, r_tree.second)
                };
        
        

    }
    int rob(TreeNode* root) {
        
        pair<int, int> res =  dfs(root);
        return max(res.first, res.second);
    }
};