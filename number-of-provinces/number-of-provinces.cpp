class Solution {
public:
    vector<bool> visited;
    int N;
    
    void dfs(vector<vector<int>>& isConnected, int node) {
        
        visited[node] = true;
        
        // loop over neighbours !
        for(int i = 0; i < N; ++i) {
            if(isConnected[node][i] == 1 && !visited[i])
                dfs(isConnected, i);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        N = isConnected.size();
        visited.resize(N, false);
        
        int c = 0;
        for(int i = 0; i < N; ++i) {
            // cout << "checking node: " << i << "\n";
            if(!visited[i]) {
                dfs(isConnected, i);
                ++c;
            }
                
        }
        
        return c;
        
    }
};