typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vvi dp;
        
        int M = obstacleGrid.size();
        int N = obstacleGrid[0].size();
        
        dp.resize(M, vi(N, 0));
        
        (obstacleGrid[0][0] == 1)?dp[0][0] = 0:dp[0][0] = 1;;
        
        for(int i =1; i < M; ++i) {
             if(obstacleGrid[i][0] == 1)
                    dp[i][0] = 0;
            else
                dp[i][0] = dp[i-1][0];
        }
        
        for(int j = 1; j < N; ++j) {
             if(obstacleGrid[0][j] == 1)
                    dp[0][j] = 0;
            else
                dp[0][j] = dp[0][j-1];
        }
        
        for(int i = 1; i<M; ++i) {
            for(int j = 1; j < N; ++j) {
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[M-1][N-1];
    }
};