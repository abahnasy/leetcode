class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        vector<vector<int>> dp (M, vector<int>(N, 0));
        
        for(int i = M-1; i >=0; --i) {
            for(int j = N-1; j >=0; --j) {
                // cout << "indices: " << i << ", " << j << "\n";
                int local = dungeon[i][j];
                if(i == M-1 && j == N-1)
                    dp[M-1][N-1] = dungeon[M-1][N-1];
                else if(i == M-1) 
                    local += dp[i][j+1];
                else if (j == N-1) 
                    local += dp[i+1][j];
                else 
                    local += max(dp[i+1][j], dp[i][j+1]);
                // cout << "   local before " << local << "\n";
                dp[i][j] = (local>0)?0:local;
                // cout << "   local after " << dp[i][j] << "\n";
            }
        }
        
        // for (auto r: dp) {
        //     for (auto e: r) {
        //         cout << e << ", ";
        //     }
        //     cout << "\n";
        // }
        
        return 1 + abs(dp[0][0]);
    }
};