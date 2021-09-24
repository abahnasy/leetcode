class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", 0, 0, n);
        return res;
    }
    void addingpar(vector<string> &v, string str, int l, int r, int n){
        if(str.size() == 2*n) {
            v.push_back(str);
            return;
        }
        if(l < n){ addingpar(v, str+"(", l+1, r, n); }
        if(r < l){ addingpar(v, str+")", l, r+1, n); }
    }
    
};