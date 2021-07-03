// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
        
//         vector<int> dp(nums.size());
//         int max_sum = nums[0];
//         dp[0] = nums[0];
//         for(int i = 1; i < nums.size(); ++i) {
//             dp[i] = max(dp[i-1]+nums[i], nums[i]);
//             if(max_sum < dp[i]) max_sum = dp[i];
//         }
//         return max_sum;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int last = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            last = max(last+nums[i], nums[i]);
            max_sum = max(max_sum, last);
        }
        return max_sum;
    }
};