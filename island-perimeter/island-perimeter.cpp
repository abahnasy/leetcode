class Solution {
public:
    vector<vector<int>> dir = {{-1,0}, {1, 0}, {0,-1}, {0,1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        int c = 0;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(!grid[i][j])
                    continue;
                // 4 corners checks
                for(int k = 0; k < 4; ++k) {
                    int new_i = i + dir[k][0];
                    int new_j = j + dir[k][1];
                    if(new_i < 0 || new_i >= M || 
                       new_j < 0 || new_j >= N 
                       || grid[new_i][new_j] == 0
                      ) {
                        ++c;
                    }
                }
                
            }
        }
        
        return c;
    }
};