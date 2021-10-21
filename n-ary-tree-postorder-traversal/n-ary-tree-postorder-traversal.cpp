/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
    void rec(Node* root) {
        if(!root) return;
        for(auto n: root->children) {
            rec(n);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        // first do recursive call on the children
        // process current node
         rec(root);
        
        return res;
    }
};