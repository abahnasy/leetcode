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
    vector<vector<int>> res;
    int target;
    vector<int> running;
    
    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        } else if (node->left == nullptr && node->right==nullptr) {
             int total = 0;
            for(auto e: running)
                total += e;
            total += node->val;
            if(total == target) {
                running.push_back(node->val);
                res.push_back(running);
                running.erase(running.end()-1);
            }
        } else {
            running.push_back(node->val);
            dfs(node->left);
            dfs(node->right);
            running.erase(running.end()-1);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        dfs(root);
        return res;
        
    }
};