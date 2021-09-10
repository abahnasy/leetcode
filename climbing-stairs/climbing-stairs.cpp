class Solution {
public:
    vector<int> dp;
    int rec(int n) {
        if (n < 0) 
            return 0;
        if(dp[n] != -1)
            return dp[n];
        if(n == 0) 
            return dp[0] = 1;
        
        return dp[n] = rec(n-1) + rec(n-2);
        
    }
    int climbStairs(int n) {
        dp.resize(n+1, -1);
        return rec(n);
    }
};