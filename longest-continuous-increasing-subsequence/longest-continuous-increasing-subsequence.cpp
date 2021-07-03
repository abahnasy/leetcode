class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1;
        int c = 1;
        for (int i = 1;  i < nums.size(); ++i) {
            if(nums[i] > nums[i-1]) {
                c++;
            } else {
                c = 1;
            }
            res = max(res, c);
            // cout << res << i << "\n";
        }
        return res;
    }
};