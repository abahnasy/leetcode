class Solution {
public:
    int N,M;
    vector<vector<int>> dp;
    
    int rec(int i, int j) {
        // base case
        if(i >= M){
            return 0;
        }
            
        if(j>= N) {
            return 0;
        }
            
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
            
        if(i == M-1 && j == N-1) {
            dp[i][j] = 1;
            return dp[i][j];
        }
            
        
        
        dp[i][j] =  rec(i+1, j) + rec(i, j+1);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n, -1));
        N = n;
        M = m;
        // base case
        // recursion
        return  rec(0,0);
            
    }
};