class Solution {
public:
    
    
    bool isValid(string s) {
       
        stack<char> st;
        for(char e: s) {
            if(e == '{' || e == '(' || e == '[') {
                st.push(e);
            } else {
                if(st.empty()) return false;
                char t = st.top();
                st.pop();
                if(e == ']' && t != '[')
                    return false;
                else if(e == '}' && t != '{')
                    return false;
                else if (e == ')' && t != '(')
                    return false;
                
            }
        }
        
        return st.empty();
    }
};