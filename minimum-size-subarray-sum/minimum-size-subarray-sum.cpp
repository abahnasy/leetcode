class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curr_sum = 0;
        int l = 0;
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            curr_sum += nums[i];
            
            while(curr_sum >= target) {
                res = min(res, i+1 - l);
                curr_sum -= nums[l];
                ++l;
            }
        }
        
        return (res == INT_MAX)? 0:res;
    }
};