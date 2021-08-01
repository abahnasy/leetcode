class Solution {
public:
    int M, N;
    vector<vector<bool>> visited;
    
    vector<int> r_coor = {-1, 1, 0, 0};
    vector<int> c_coor = {0, 0, -1, 1};
    
    bool dfs(vector<vector<char>>& grid, int r, int c) {
        
        visited[r][c] = true; // invalidate cell
        
        if(grid[r][c] == '0')
            return false;
        
       // invalidate neighbours
        for(int i = 0; i < 4 ; ++i) {
            int new_r = r+ r_coor[i];
            int new_c = c + c_coor[i];
            if(new_r >= M || new_r < 0 || new_c >= N || new_c < 0)
                continue;
            if(!visited[new_r][new_c])
                dfs(grid, new_r, new_c);
        }
        
        
        
        
        // invalidate neighbours
        // for(int i = 0; i < 4 ; ++i) {
        //     dfs(grid, r + r_coor[i], c + c_coor[i]);
        // }
            
        return true;
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        M = grid.size();
        N = grid[0].size();
        visited.resize(M);
        for(int i = 0; i < M; ++i) {
            visited[i].resize(N, false);
        }
        int count = 0;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(!visited[i][j]) {
                    if(dfs(grid, i, j))
                        ++count;
                }
                    
            }
        }
        
        return count;
    }
};