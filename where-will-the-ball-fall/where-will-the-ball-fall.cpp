class Solution {
public:
    int rec(vector<vector<int>>& grid, int r, int c) {
        if(r == grid.size())
            return c;
        
        if(grid[r][c] == 1 && c < grid[0].size()-1 && grid[r][c+1] == 1)
            return rec(grid, r+1, c+1);
        else if(grid[r][c] == -1 && c > 0 && grid[r][c-1] == -1)
            return rec(grid, r+1, c-1);
        else 
            return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        
        vector<int> res;
        
        for(int j = 0; j < N; ++j) {
            res.push_back(rec(grid, 0, j));    
        }
        
        return res;
    }
};