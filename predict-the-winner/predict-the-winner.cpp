class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0,0}));
        for(int i =0; i< n; ++i) {
            dp[i][i] = {nums[i], 0};
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n-1-i; ++j ) {
                
                int opt1 = nums[j] + dp[j+1][j+i+1].second;
                int opt2 = nums[j+1+i]  + dp[j][j+i+1-1].second;
                int p1 = 0;
                int p2 = 0;
                if(opt1>opt2) {
                    p1 = opt1;
                    p2 = dp[j+1][j+i+1].first;
                } else {
                    p1= opt2;
                    p2 = dp[j][j+i+1-1].first;
                }
                dp[j][j+i+1] = {p1, p2};
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