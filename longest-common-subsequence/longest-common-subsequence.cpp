class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int M = text1.size();
        int N = text2.size();
        vector<vector<int>> dp (M+1, vector<int>(N+1, 0));
        for(int i = 1; i <= M; ++i) {
            for(int j = 1; j <= N; ++j) {
                if(text1[i-1] == text2[j-1]) {
                    // cout << "similar " << text1[i] << " = " << text2[j] << "\n";
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                    
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // for(int i = 0; i <= M; ++i) {
        //     for(int j = 0; j <= N; ++j) {
        //         cout << dp[i][j] << ", ";
        //     }
        //     cout << "\n";
        // }
        
        
        
        
        return dp[M][N];
    }
};