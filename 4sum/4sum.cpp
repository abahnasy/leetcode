class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); ++i) {
            
            // if(nums[i] > target) return res;
            if(i > 0 &&nums[i] == nums[i-1])
                continue;
            cout << ">>>>> outer loop: " << nums[i] << "\n";
            for(int j = i + 1; j < nums.size(); ++j) {
                
                // if(nums[i] + nums[j] > target)
                //     return res;
                if(j-1!= i && nums[j] == nums[j-1])
                    continue;
                cout << "second loop: " << nums[j] << "\n";
            
                int l = j+1;
                int r = nums.size() - 1;
                while(l < r ) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum < target)
                        ++l;
                    else if(sum > target)
                        --r;
                    else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l;--r;
                        while(l < nums.size() && nums[l] == nums[l-1])
                        ++l;
                        while( r >= 0 && nums[r] == nums[r+1])
                            --r;
                    }
                }
                
            }    
        }
        return res;
    }
};