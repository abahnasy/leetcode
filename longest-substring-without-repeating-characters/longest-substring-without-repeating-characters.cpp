class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0; // edge case
        unordered_map<char, int>m;
        
        int _max = 0;
        int l = 0;
        for(int i = 0; i < s.size(); ++i) {
            // if c is not seen
            if(m.find(s[i]) == m.end())
                _max = max(_max, i-l+1);
            else {
                if(m[s[i]] < l) {
                    _max = max(_max, i-l+1);
                } else {
                    l = m[s[i]] + 1;
                }
            }
            
            m[s[i]] = i;
                // before l
                // after l
            
        }
        
        return _max;
    }
};

//idx                 |
//      a b c a b c b b
//                    l
