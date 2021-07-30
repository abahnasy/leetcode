class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int N = nums.size();
        N = pow(2, N);
        
        for(int i = 0; i < N; ++i) {
            // i should be represented as binary
            vector<int> temp_res = vector<int>();
            int idx = 0;
            int temp = i;
            while(temp) {
                // cout << "investigating " << temp << "\n";
                if (temp&0x01) {
                    temp_res.push_back(nums[idx]);
                }
                temp = temp >> 1;
                ++idx;
                
            }
            res.push_back(temp_res);
            
            
        }
        return res;
        
    }
};