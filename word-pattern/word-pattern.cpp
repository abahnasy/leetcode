class Solution {
public:
    
    bool wordPattern(string pattern, string s) {
        map<string, int> m;
        vector<int> cm (26, 0);
        stringstream ss (s);
        int N = pattern.size();
        string token;
        int i = 0;
        for(int j = 0; ss >> token; ++i) {
            
            if(i == N || m[token] != cm[pattern[i] - 'a'])
                return false;
            else
                m[token] = i+1;
                cm[pattern[i] - 'a'] = i+1;
            
        }
        
        return (i == N);
        
    }
        
        
};