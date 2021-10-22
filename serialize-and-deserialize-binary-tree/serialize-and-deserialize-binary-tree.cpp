/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void _serialize(TreeNode* root, stringstream& ss) {
        if(!root) {
            ss << "X ";
            return;
        }
        ss << root->val << " ";
        _serialize(root->left, ss);
        _serialize(root->right, ss);
        
    }
    
    TreeNode* _deserialize(stringstream& ss) {
        string val;
        ss >> val;
        if(val == "X") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = _deserialize(ss);
        root->right = _deserialize(ss);
        
        return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        _serialize(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss (data);
        return _deserialize(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));