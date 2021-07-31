class Solution {
public:
    
    

    vector<int> copy_v(vector<int>& v) {
        vector<int> res;
        for(auto e: v) {
            res.push_back(e);
        }
        
        return res;
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        
        subsets.push_back({});
        
        int N = nums.size();
        
        for (int i = 0; i < N; ++i) {
            vector<vector<int>> new_subsets;
            for(auto v: subsets) {
                vector<int> temp = copy_v(v);
                temp.push_back(nums[i]);
                new_subsets.push_back(temp);
            }
            
            // new_subsets.push_back({nums[i]});
            
            for( auto v: new_subsets) {
                subsets.push_back(v);
            }
        }
        
        
        return subsets;
       
            
    }
};