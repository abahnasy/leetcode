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
    int rec(Node* root) {
        if(!root) return 0;
        int _max = 0;
        for(auto n: root->children) {
            _max = max(_max, rec(n));
        }
        
        return _max + 1 ;
    }
    int maxDepth(Node* root) {
        
        return rec(root);
        
    }
};