class Solution {
public:
    vector<vector<int>> res;
    int N;

    void bt(vector<int>& nums, vector<int>& temp, int idx) {
       
        res.push_back(temp);
        for(int i = idx; i < N; ++i) {
            if((i == idx) || (nums[i] != nums[i-1])) {
                temp.push_back(nums[i]);
                bt(nums, temp, i+1);
                temp.erase(temp.end()-1);
                
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        N = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        bt(nums, temp, 0);
        
        return res;
    }
};