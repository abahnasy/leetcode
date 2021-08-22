class Solution {
public:
    
    int rob_helper(vector<int>& nums, int l) {
        
        
        vector<int> dp(nums.size()-1, 0);
        dp[0] = nums[l];
        dp[1] = max(nums[l], nums[l+1]);
        for(int i = 2; i < nums.size()-1; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[l+i]);
        }
        
        return dp[nums.size() - 2];
        
        
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return (nums[0] > nums[1])? nums[0]: nums[1];
        int r1 = rob_helper(nums, 0);
        int r2 = rob_helper(nums, 1);
        return (r1>r2)?r1:r2;
    }
};