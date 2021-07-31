class Solution {
public:
    vector<vector<int>> res;
    int N;
    int K;
    
    void backtrack(int idx, vector<int>& curr, vector<int>& nums) {
        if(curr.size() == K) {
            res.push_back(vector<int>(curr.begin(), curr.end()));
            return;
        }
        for(int i = idx; i < N; ++i) {
            curr.push_back(nums[i]);
            backtrack(i+1, curr, nums);
            curr.erase(curr.end()- 1);
        }
            
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        N = nums.size();
        vector<int> curr = {};
        for(K = 0; K < N+1; ++K) {
            backtrack(0, curr, nums);
        }
        
        return res;
        
    }
};