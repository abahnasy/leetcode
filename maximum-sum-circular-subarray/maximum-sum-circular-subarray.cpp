class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int curr_max = 0;
        int _max = nums[0];
        int curr_min = 0;
        int _min = nums[0];
        
        for(auto n: nums) {
            total += n;
            curr_max = max(curr_max +n, n);
            _max = max(_max, curr_max);
            curr_min = min(curr_min + n, n);
            _min = min(_min, curr_min);
        }
        
        return (_max > 0)? max(_max, total - _min): _max ;
    }
};