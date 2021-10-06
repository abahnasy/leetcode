class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> res;
        for(auto n:nums) {
            if(m.count(n) > 0) {
                res.push_back(n);
            }
            m[n]++;
        }
        
        return res;
    }
};