class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};





// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         // choose upperbound value, either amount+1 or INT_MAX
//         vector<int>dp(amount+1, INT_MAX);
//         dp[0] = 0;
//         for(int i = 0; i <= amount; ++i) {
//             for(auto coin: coins) {
//                 if(i-coin <0)
//                     continue;
//                 cout << "filling " << i << "\n";
//                 dp[i] = min(dp[i-coin]+1, dp[i]);
//             }
//             cout << "final: dp[" << i << "] = " << dp[i] << "\n"; 
//         }
        
//         return (dp[amount] == amount+1)?-1:dp[amount];
//     }
// };