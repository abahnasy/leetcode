class Solution {
public:
    int numSquares(int n) {
        if(n<=3) return n;
        // generate perfect squares up to n
        // build dp from 1 to n 
        // return dp[n]
        vector<int> perfect_list;
        int i = 1;
        
        while(i*i <= n) {
            perfect_list.push_back(i*i);
            ++i;
        }
        
        for(auto e: perfect_list){
           
            if(e == n) return 1;
        }
        
        
        vector<int>dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i <= n ; ++i) {
            dp[i] = INT_MAX;
            for(auto e: perfect_list) {
                if(e <= i) {
                    dp[i] = min(dp[i], 1+dp[i-e]);
                }
            }
        }
        

        return dp[n];
            
    }
};