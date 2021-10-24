class Solution {
public:
    int lengthOfLongestSubstring(string s) {        
        if(s.size() <= 1) return s.size();
        unordered_map<char, int> m;
        
        int max_ = 0;
        
        for(int i = 0, j = 0; i < s.size(); ++i) {
            if(m.count(s[i]) != 0) {     
                j = max(m[s[i]]+1, j);
                
            }
            m[s[i]]= i;
            max_ = max(max_, i-j+1);
            cout << max_ << "\n";
            
        }
        
        return max_;
        
    }
};
// map<char, int> m;
// max = 2

//        |
// "a b b a"
//     |