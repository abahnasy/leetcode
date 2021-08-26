class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) 
            return 0;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        // for(int i = 0; i < N; ++i) {dp[i][i] = nums[i];}
        for(int len = 0; len<N; ++len) {
            for(int i = 0; i+len <N; ++i) {
                int j = len+i;
                // cout << "filling " << i <<", " << j <<"\n";
                for(int k = i; k <= j; ++k) {
                    // cout << " K is " << k <<"\n";
                    // define boundaries
                    int left_bound = (i == 0)? 1: nums[i-1];
                    int right_bound = (j == N-1)? 1: nums[j+1];
                    int left = (k == i) ? 0 : dp[i][k-1];
                    int right = (k == j) ? 0 : dp[k+1][j];
                    
                    dp[i][j] = max(dp[i][j], left_bound*nums[k]*right_bound + left + right);
                    // cout << " opitons: " << dp[i][j] << "\n";
                }
                
            }
        }
        
        // for(int i = 0; i < N; ++i) {
        //     for(int j = 0; j < N; ++j) {
        //         cout << dp[i][j] << ", ";
        //     }
        //     cout << "\n";
        // }
        
        return dp[0][N-1];
    }
};