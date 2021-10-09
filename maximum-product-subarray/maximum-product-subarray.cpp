class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int _max = nums[0];
        int last_min = nums[0];
        int last_max = nums[0];
        for(int i = 1 ; i < nums.size(); ++i) {
            if(nums[i]<0) {
                int temp = last_min;
                last_min = last_max;
                last_max = temp;
            }
            last_max = max(nums[i], last_max*nums[i]);
            last_min = min(nums[i], last_min*nums[i]);
            _max = max({_max, last_min, last_max});
        }
        
        return _max;
    }
};