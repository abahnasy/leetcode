class Solution {
public:
    // unordered_map<string, int> dp;
    unordered_map<int, int> dp;
    int rec(string& s, int p) {
    
        if (p == s.size()) {
            return 1;
        }
        if(dp.find(p) != dp.end())
            return dp[p];
        
        
        int res = 0;
        if((s[p] - '0') > 0)
            res += rec(s, p+1);
        if(p < (s.size()-1) && (s[p] == '1' || (s[p] == '2' && (s[p+1] - '0') < 7)))
            res += rec(s, p+2);
        
        dp[p] = res;
        
        return res;
        
    }
    
    int numDecodings(string s) {
        // handle edge cases
        int res =  rec(s, 0);
        return res;
    }
};