class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int min_running = prices[0];
        int max_ = 0;
        for(int i = 0; i < prices.size(); ++i ) {
            if (prices[i] < min_running) {
                min_running = prices[i];
                int max_ = 0;
                
            }
            max_ = max(prices[i] - min_running, max_);
            
        }
        
        return max_;
    }
};