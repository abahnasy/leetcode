/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool get_path(TreeNode* root, TreeNode* t, vector<TreeNode*>& path) {
        if(!root) return false;
        if(root == t) {
            path.push_back(root);
            return true;
        }
        if(get_path(root->left, t, path) || get_path(root->right, t, path)) {
            path.push_back(root);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;
        get_path(root, p, p_path);
        get_path(root, q, q_path);
        
        for(auto& p: p_path) {
            for(auto& q: q_path) {
                if(p == q) return q;
            }
        }
        
        return NULL;
    }
};

/*
  1
  |\
  2 5
  |
  3
 /\
5 4

[1]
[5,1]


*/