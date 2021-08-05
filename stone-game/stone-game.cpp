class Solution {
public:
    vector<vector<int>> dp;
    
    int help(vector<int>& piles, int i, int j) {
        if(i > j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        else {
            dp[i][j] = max(piles[i] - help(piles, i+1, j), 
                           piles[j] - help(piles, i, j-1)
                          );
            return dp[i][j];
        }
        
    }
    
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();
        dp.resize(N, vector<int>(N, -1));
        
        return help(piles, 0, N-1) > 0;
   
   
   
        
         
    }
};