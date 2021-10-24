class Solution {
public:
    int max_freq(unordered_map<char, int>& m) {
        int res = 0;
        for(auto c: m) {
            res = max(res, c.second);
        }
        return res;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int res = 0;
        for(int i = 0,  j = 0; i < s.size(); ++i) {
            m[s[i]]++;
            // cout << " processing " << s[i] << "\n";
            if((i-j+1 - max_freq(m)) > k) {
                // cout << "   if\n";
                m[s[j]]--;
                j+=1;
            } else {
                // cout << "   else\n";
                
                res = max(res, i-j+1);    
            }
            
        }
        
        return res;
    }
};
//1234
//AABABBA