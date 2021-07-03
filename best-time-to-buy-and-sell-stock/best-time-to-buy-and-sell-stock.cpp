class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_p = 0;
        vector<int> dp(prices.size());
        dp[0] = prices[0];
        for(int i = 1; i < n; ++i) {
            dp[i] = min(dp[i-1], prices[i]);
            max_p = max(max_p, prices[i] - dp[i]);
        }
        return max_p;
        
    }
};