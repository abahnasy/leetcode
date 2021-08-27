class Solution {
public:
    unordered_map <int, int >dp;
    int rec (vector<int>& cost, int n) {
        if(n >= cost.size())
            return 0;
        if(dp.find(n) != dp.end())
            return dp[n];
        dp[n] =cost[n] + min(rec(cost, n+1), rec(cost, n+2)); 
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 0)
            return 0;
        return min (rec(cost, 0), rec(cost, 1));
    }
};