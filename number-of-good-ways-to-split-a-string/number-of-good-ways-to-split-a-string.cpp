class Solution {
public:
    int numSplits(string s) {
        set<char> s1;
        set<char> s2;
        unordered_map<char, int>m;
        int c = 0;
        // prepare the inputs
        
        for(int i = 0; i < s.size(); ++i) {
            s2.insert(s[i]);
            m[s[i]]++;
        }
        
        // for(auto e: s2) {
        //     cout << e << ", ";
        // }
        // cout << "\n";
        // for(auto e: m) {
        //     cout << e.first << ": " << e.second << "\n";
        // }
        
        // check all possible splits
        for(int i = 0; i < s.size()-1; ++i) {
            // cout << "idx: " << i << "\n";
            // prepare for the next split
            s1.insert(s[i]);
            if(m[s[i]] == 1) {
                auto it = s2.find(s[i]);
                s2.erase(it);  
            } 
            m[s[i]]--;
            
            // printf("s1: %d, s2: %d\n", s1.size(), s2.size());
            
            if(s1.size() == s2.size()) 
                ++c;
        }
        
        return c;
    }
};