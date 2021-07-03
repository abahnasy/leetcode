class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0) return 0;
        
        vector<int>dp(n,1);
        for(int i = 1; i < n; ++i) {
            if(nums[i]>nums[i-1]) {
                dp[i] = max(dp[i], dp[i-1]+1);
                
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};