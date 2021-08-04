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
    int t;
    bool dfs(TreeNode* node, int prev_sum) {
        if(node == nullptr)
            return false;
        if(node->left == nullptr && node->right == nullptr) {
            if(prev_sum + node->val == t)
                return true;
        } else {
            if(dfs(node->left, prev_sum + node->val)) {
                return true;
            }
            if(dfs(node->right, prev_sum + node->val)) {
                return true;
            }
        }
        
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        return dfs(root, 0);
        
    }
};