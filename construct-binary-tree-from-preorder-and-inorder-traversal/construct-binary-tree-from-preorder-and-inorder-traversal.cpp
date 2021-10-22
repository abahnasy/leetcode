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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int prestart, int instart, int inend) {
        if(prestart >= preorder.size() || instart >inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int rootIdx = 0;
        for(int i = instart; i <= inend ; ++i) {
            if(inorder[i] == preorder[prestart]) rootIdx = i;
        }
        root->left = helper(preorder, inorder, prestart+1, instart, rootIdx-1);
        root->right = helper(preorder, inorder, prestart+1+rootIdx-instart, rootIdx+1, inend);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 0, inorder.size()- 1);
    }
};