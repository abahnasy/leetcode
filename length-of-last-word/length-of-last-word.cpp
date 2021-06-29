class Solution {
public:
    int lengthOfLastWord(string s) {
        int last = 0;
        int c = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == ' ' && c != 0) {
                last = c;
                c = 0;
            }else if (s[i] == ' '){
                continue;
            } else {
                c++;
            }
            
        }
        if (c == 0) {
            return last;
        } else {
            return c;
        }
        
    }
};