class Solution {
public:
    vector<bool> visited;
    void dfs(vector<vector<int>>& rooms, int node) {
        visited[node] = true;
        for(auto e: rooms[node]) {
            if(!visited[e])
                dfs(rooms, e);
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        visited.resize(N, false);
        dfs(rooms, 0);
        
        for(auto e: visited) {
            if(!e)
                return false;
        }
        return true;
    }
};