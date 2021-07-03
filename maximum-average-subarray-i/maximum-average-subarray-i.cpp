class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        // corner cases
        if (n <= k) {
            double total = 0;
            for(int n: nums)
                total += n;
            return total / k;
        }
        double win_sum = 0;
        for(int i = 0; i < k;++i) {
            win_sum += nums[i];
        }
        // cout << "DEBUG: "<< win_sim << "\n";
        double max_ = win_sum/k;;
        for(int i = k; i < n; ++i) {
            win_sum -=nums[i-k];
            win_sum += nums[i];
            max_ = max(max_, win_sum/k);
        }
        
        return max_;
    }
};

//[0,1,2,3,4,5,6,7,8]