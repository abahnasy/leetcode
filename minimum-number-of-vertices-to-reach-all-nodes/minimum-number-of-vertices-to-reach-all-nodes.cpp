typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vector<int>> vii;


class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vi in(n, false);
        for(auto e: edges)
            in[e[1]] = true;
        
        vi res;
        for(int i = 0; i < n; ++i) {
            if(in[i]) continue;
            res.push_back(i);
                
                
        }
        
        return res;
            
    }
};