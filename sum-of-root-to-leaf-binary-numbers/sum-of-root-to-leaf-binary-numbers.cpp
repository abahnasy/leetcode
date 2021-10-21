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
    int total = 0;
    int bin2dec(int x) {
        //TODO
        int total = 0;
        int i = 1;
        while(x>0) {
            if(x&0x01)
                total += i;
            i *= 2;
            x = x >> 1;
        }
        
        return total;
    }
    void rec(TreeNode* root, int n) {
        // base case
        if(!root) return;
        n = n<< 1;
        n += root->val;
        
        if(!root->left && !root->right) {
            // shift and add the current value   
            total += bin2dec(n);
        } 
        
        if (root->left) {
            rec(root->left, n);
        }
        if (root->right) {
            rec(root->right, n);
        }
        
    }
    int sumRootToLeaf(TreeNode* root) {
        rec(root, 0);
        
        return total;
    }
};