class Solution {
public:
    vector<vector<int>> res;
    int N;
    void helper(vector<int>& nums, vector<int> temp, int idx) {
        if(idx == N) {
            res.push_back(temp);
        } else {
            helper(nums, temp, idx+1);
            temp.push_back(nums[idx]);
            helper(nums, temp, idx+1);
            temp.erase(temp.end()-1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        N = nums.size();
        
        vector<int> temp;
        helper(nums, temp, 0);
        
        return res;
    }
};