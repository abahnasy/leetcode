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
    int count;
    int inorder(TreeNode* root, int k) {
        if(!root) return -1;
        int res = inorder(root->left, k);
        if(res != -1) return res;
        ++count;
        if(count == k) return root->val;
         res = inorder(root->right, k);
        if(res != -1) return res;
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
         return inorder(root, k);
    }
};