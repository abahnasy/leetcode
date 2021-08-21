class Solution {
public:
    unordered_map<int, int> dp;
    int rec(vector<int>& coins, int amount) {
        // for(int i = 0; i < level; ++i)
        //     cout << "  ";
        // cout << "exploring " << amount << "\n";
        if(amount == 0)
            return 0;
        if(dp.find(amount) != dp.end())
            return dp[amount];
        
        int min_c = INT_MAX;
        for(auto coin: coins) {
            if(coin > amount)
                continue;
            int val = rec(coins, amount - coin);
            min_c = min(min_c, val);
        }
        
        min_c = (min_c == INT_MAX)?min_c: min_c+1;
        dp[amount] = min_c;
        return min_c;
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        int res =  rec(coins, amount);
        if(res == INT_MAX)
            return -1;
        else
            return res;
        
    }
};