class Solution {
public:
    
    int M,N;
    vector<vector<bool>> visited;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int dfs(vector<vector<int>>& grid, int i ,int j) {
        if(i < 0 || i >= M || 
           j < 0 || j >= N || 
           grid[i][j] == 0
          ) {
            return 1;
        }
        
        if(visited[i][j])
            return 0;
                    
        visited[i][j] = true;
        int c = 0;
        for( int k = 0; k < 4; ++k ) {
            int new_i = i + dir[k][0];
            int new_j = j + dir[k][1];
            
            c+= dfs(grid, new_i, new_j);
        }
        
        return c;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        visited.resize(M, vector<bool>(N, false));
        
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(grid[i][j] == 1) {
                    // assuming only one island
                    return dfs(grid, i ,j);
                }
            }
        }
        
        return 0;
    }
};