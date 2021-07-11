class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for(string s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        
        for(auto itr = m.begin(); itr != m.end(); ++itr) {
            res.push_back(itr->second);
        }
        
        
        
        return res;
    }
};