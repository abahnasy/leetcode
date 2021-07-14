class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int>m;
        vector<int> res;
        for(int i = 0 ; i < numbers.size(); ++i) {
            m[numbers[i]] = i;
        }
        
        for(int i =0 ;i < numbers.size(); ++i) {
            if(m.find(target - numbers[i]) != m.end() && m[target-numbers[i]] != i) {
                res.push_back(i+1);
                res.push_back(m[target - numbers[i]] +1);
                break;
            }
        }
        
            
        
        return res;
    }
};