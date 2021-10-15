class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if(N<=1) return 0;
        vector<int> buy(N,0);
        vector<int> sell(N,0);
        vector<int> still(N,0);
        
        buy[0] = - prices[0];
        
        
        for(int i = 1; i < N; ++i) {
            buy[i] = max(buy[i-1], still[i-1] - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
            still[i] = max(still[i-1], sell[i-1]);
        }
        
        return max(sell[N-1], still[N-1]);
    }
};


// [1,2,3,0,2]
// [0,1,2,2, ]