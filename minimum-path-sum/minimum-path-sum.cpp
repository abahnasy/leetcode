typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
public:
    vvi dp;
    
    int rec(vector<vector<int>>& grid, int i, int j) {
        if(i< 0)
            return INT_MAX;
        if(j < 0)
            return INT_MAX;
        if(i == 0 && j == 0)
            return grid[i][j];
        
    
        return grid[i][j] + min(rec(grid,i-1,j), rec(grid,i,j-1));
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        dp.resize(M,vi(N, 0));
        
        // first row and col
        dp[0][0] = grid[0][0];
        for(int i = 1; i < M; ++i) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        
        for(int j = 1; j < N; ++j ) {
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        
        // fill the rest of the array
        for(int i = 1;i<M;++i ) {
            for(int j = 1; j < N;++j) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[M-1][N-1];
    }
};