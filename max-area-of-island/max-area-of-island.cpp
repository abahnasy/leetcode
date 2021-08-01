class Solution {
public:
    
    int max_no;
    int M, N;

    // vector<vector<bool>> visited;
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if(r >= M || r < 0 || c >= N || c < 0 || grid[r][c] == 0)
            return 0;

        // if(visited[r][c] == true)
        //     return 0;
        
        grid[r][c] = 0;
        

        // visited[r][c] = true;
        return 1 + dfs(grid, r-1, c) + dfs(grid, r+1, c) + dfs(grid, r, c-1) + dfs(grid, r, c+1);
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        max_no = 0;
        // visited.resize(N);
        // for (int i = 0 ; i < N ; i++) {
        //     visited[i].resize(N, false);
        // }

        for(int i = 0 ; i < M; ++i) {
            for(int j = 0; j < N ; ++j) {
//                visited.clear();
//                visited.resize(N);
//                for (int k = 0 ; k < N ; k++) {
//                    visited[k].resize(N, false);
//                }

                if(grid[i][j])
                    max_no = max(max_no, dfs(grid, i, j));
               
            }
        }


        return max_no;
    }
};