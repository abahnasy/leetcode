class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n  = edges.size() + 1;
        vector<int> incoming(n+1, 0);
        for(auto e: edges) {
            incoming[e[1]]++;
            incoming[e[0]]++;
        }
        
        for(int i = 0; i <= n; ++i) {
            if(incoming[i] == n-1)
                return i;
        }
        
        return -1; // never reached, guaranteed if condiditon
    }
};