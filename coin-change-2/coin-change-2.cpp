class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        
        // loop over coins with amount = 0
        for(int i =0; i < coins.size()+1 ;++i) {
            dp[i][0] = 1;
        }
        // loop over amounts with no coins
        
        for(int j = 1; j < amount+1; ++j) {
            dp[0][j] = 0;
        }
        
        for(int i = 1; i < coins.size()+1 ;++i) {
            for(int j = 1; j < amount+1; ++j) {
                // cout << i << ", " << j << endl;
                if(coins[i-1] > j) {
                    dp[i][j] = dp[i-1][j];    
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j- coins[i-1]];
                }
                
            }
        }
        
        
        return dp[coins.size()][amount];
    }
};