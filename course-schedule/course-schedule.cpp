class Solution {
public:
    vector<vector<int>> adjList;
    vector<int> visited; // 0: unvisited 1:visited 2: current
    
    bool dfs(int node) {
        visited[node] = 2;
        // loop over neighbours
        for(auto e: adjList[node]) {
            if(visited[e] == 2)
                return false;
            if( visited[e] == 0 ) {
                if(!dfs(e))
                    return false;
            }
        }
        visited[node] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adjList.resize(numCourses);
        visited.resize(numCourses, false);
        // create a graph from the preq
        for(auto v: prerequisites) {
            for(int i = 1; i < v.size(); ++i) {
                adjList[v[i]].push_back(v[0]);
            }
        }
        
        
        for(int i =0; i < numCourses; ++i) {
            if(!visited[i])
                if(!dfs(i))
                    return false;
        }
        return true;
        
      
        
        
    }
};