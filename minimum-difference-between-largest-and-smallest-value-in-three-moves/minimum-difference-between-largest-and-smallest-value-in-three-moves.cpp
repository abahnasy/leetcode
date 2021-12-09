class Solution {
public:
    int minDifference(vector<int>& nums) {
        // size below 4 return 0
        if(nums.size()<=4) return 0;
        sort(nums.begin(), nums.end());
        int min_ = INT_MAX;
        //remove first three
        min_ = min(min_, nums[nums.size()-1] - nums[3]);
        // remove first two and last one
        min_ = min(min_, nums[nums.size()-2] - nums[2]);
        // remove first one and last two
        min_ = min(min_, nums[nums.size()-3] - nums[1]);
        // remove last three
        min_ = min(min_, nums[nums.size()-4] - nums[0]);
            
            
        return min_;
    }
};