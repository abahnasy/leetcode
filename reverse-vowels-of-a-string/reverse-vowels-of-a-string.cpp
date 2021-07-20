class Solution {
public:
 bool m_isVowel(char ch)
  {
    return (
        ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
  }
    
    string reverseVowels(string s) {
        string v  = "aeoiuAEOIU";
        char l = 0;
        char r = 0;
        int N = s.size();
        int i = 0; 
        int j = s.size()-1;
        while(i < j) {
            if(!m_isVowel(s[i])) {
                ++i;
            }
            
            else if(!m_isVowel(s[j])) {
                --j;
            }
            
            else {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                ++i; --j;
            }
            
            
            
        }
        
        return s;
    }
};