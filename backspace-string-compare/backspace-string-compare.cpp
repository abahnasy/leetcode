class Solution {
public:
    // string stack_to_str(stack<char>& st) {
    //     stringstream ss;
    //     while(!st.empty()) {
    //         ss << st.top();
    //         st.pop();
    //     }
    //     return ss.str();
    // }
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        for(char c: s) {
            if(c != '#')
                s1.push(c);
            else
                if(!s1.empty())
                    s1.pop();
            
        }
        // cout << "updated s1 " << stack_to_str(s1) <<"\n"; 
        
        for(char c: t) {
            if(c != '#')
                s2.push(c);
            else
                if(!s2.empty())
                    s2.pop();
                    
        }
        // cout << "updated s2 " << stack_to_str(s2) <<"\n"; 
        while(!s1.empty() && !s2.empty()) {
            cout << "cpmaring " << s1.top() << s2.top() << "\n";
            if(s1.top() != s2.top()) {
                return false;
            }
            s1.pop(); s2.pop();
        }
        
        
        return (s1.empty() && s2.empty());
    }
};