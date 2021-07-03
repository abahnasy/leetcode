class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        
        long long int t = 1;
        int zero_count = 0;
        int zero_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                ++zero_count;
                zero_idx = i;
            } else {
                t *= nums[i];    
            }
            
        }
        
        // check zeros
        if(zero_count > 1)
            return ans;
        else if (zero_count == 1) {
            ans[zero_idx] = t;
            return ans;
        } else {
            
            for (int i = 0; i < n; ++i) {

                ans[i] = t/nums[i];
            }
        
        return ans;
            }
            
    }
};