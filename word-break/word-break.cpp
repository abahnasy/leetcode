class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        
        for(int i = 1; i <= s.size(); ++i) {
            for(string word: wordDict) {
                
                if(word.size() <= i) {
                    cout << "will check i=" <<i<<", word: " << word << " substring: " << s.substr(i-word.size(), word.size()) <<"\n";
                    if (word == s.substr(i-word.size(), word.size())) {
                        cout << "matched word with i=" << i <<", word=" << word <<"\n";
                        cout << "substring: "<< s.substr(i-word.size(), word.size()) << "\n";
                        if(dp[i-word.size()] == true)
                            dp[i] = true;    
                    }
                    
                }
                    
            }
        }
        cout << "Resultant: ";
        for(auto e: dp) {
            cout << e <<", ";
        }
        cout << endl;
        
        return dp[s.size()];
    }
};