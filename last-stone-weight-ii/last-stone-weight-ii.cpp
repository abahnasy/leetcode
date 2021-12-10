class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;
        // get the total sum
        for(int s: stones) total += s;
        int dp_size = total / 2;
        vector<vector<int>> dp (stones.size()+1, vector<int> (dp_size+1, 0));
        for(int i = 1; i <= stones.size(); ++i) {
            for(int j = 1; j <= dp_size; ++j) {
                if(j-stones[i-1] >= 0)
                    dp[i][j] = max(stones[i-1] + dp[i-1][j-stones[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return total - 2*dp[stones.size()][dp_size];
        
        // return 0;
    }
};