class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // add elements in a map with true value
        // loop over every element
        // subtract it from the target
        // check whether the remaing in the map or not
        unordered_map<int, int>m;
        vector<int> res;
        for(int i = 0 ; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }
        
        for(int i =0 ;i < nums.size(); ++i) {
            if(m.find(target - nums[i]) != m.end() && m[target-nums[i]] != i) {
                res.push_back(i);
                res.push_back(m[target - nums[i]]);
                break;
            }
        }
        
            
        
        return res;
    }
};