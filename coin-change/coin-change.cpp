typedef vector<int> vi;
typedef vector<vector<int>> vii;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vi dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 0; i <=  amount; ++i ) {
            for (int j = 0; j < coins.size(); ++j) {
                if(i >= coins[j]) {
                    dp[i] = min(dp[i] , dp[i-coins[j]] +1);
                } else {
                    break;
                }
            }
        }
        
        if(dp[amount] <= amount) {
            return dp[amount];
        } else {
            return -1;
        }
        
    }
};