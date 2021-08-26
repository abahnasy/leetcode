class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0,0}));
        for(int i =0; i< n; ++i) {
            dp[i][i] = {nums[i], 0};
        }
        
        for(int len = 1; len < n; ++len) {
            for(int i = 0; i < n-len; ++i ) {
                int j = i+len;
                int opt1 = nums[i] + dp[i+1][j].second;
                int opt2 = nums[j]  + dp[i][j-1].second;
                int p1 = 0;
                int p2 = 0;
                if(opt1>opt2) {
                    p1 = opt1;
                    p2 = dp[i+1][j].first;
                } else {
                    p1= opt2;
                    p2 = dp[i][j-1].first;
                }
                dp[i][j] = {p1, p2};
            }
        }
        
//         for(int i = 0; i < n; ++i) {
//             for(int j = 0; j < n; ++j) {
                
//                 cout << "(" << dp[i][j].first << ", " << dp[i][j].second << "), ";
//         }
//             cout << "\n";
//         }
        
        return (dp[0][n-1].first >= dp[0][n-1].second)? true: false;
    }
};