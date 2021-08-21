class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>>dp (coins.size()+1, vector<int>(amount+1, 0));
        
        for(int i = 0; i < coins.size()+1; ++i) {
            dp[i][0] = 1;
        }
        
        for(int j = 1; j < amount+1; ++j) {
            dp[0][j] = 0; 
        }
        
        
        for(int i =1; i <= coins.size(); ++i) {
            for(int j = 1; j <= amount; ++j) {
                // cout << "accessing: " << i <<", " << j << "\n";
                // cout << "coin: "<< coins[i-1] << " amount: " << j << "\n";
                if(coins[i-1] > j) {
                    // cout << "coin " << coins[i-1] << "is greater than the amount " << amount << "\n";
                    
                    dp[i][j] = dp[i-1][j];
                } else {
                    int col = j - coins[i-1];
                    // cout << "Value after using the coin " << coins[i-1] << "is " << dp[i][col] << "\n";
                    // cout << "accessing: " << i <<", " << j << "\n";
                    dp[i][j] = dp[i-1][j] + dp[i][col];    
                }
                
            }
        }
        
        return dp[coins.size()][amount];
        
    }
};