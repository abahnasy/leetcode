class Solution {
public:
    bool dfs (vector<bool>& visited, vector<vector<int>>& adj, int start, int end) {
        // cout << "star and end are: " << start << ", " << end << "\n";
        if(start == end)
            return true;
        
        visited[start] = true;
        for(auto u: adj[start]) {
            if(visited[u]) continue;
            if(dfs(visited, adj, u, end))
                return true;
        }
        return false;
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        
            
        return dfs(visited, adj, start, end);
    }
};