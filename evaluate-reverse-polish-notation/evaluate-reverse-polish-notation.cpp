class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        vector<string> ops = {"+", "*", "-", "/"};
        
        for( string s: tokens) {
            
            if(find(ops.begin(), ops.end(), s) == ops.end()) {
                st.push(stoi(s));
            } else {
                // perform operation
                int o2 = st.top(); st.pop();
                int o1 = st.top(); st.pop();
                
                if(s == "+") {
                    st.push(o1 + o2);
                } else if (s == "-") {
                    st.push(o1 - o2);
                } else if (s == "/") {
                    st.push((o1 / o2));
                } else { // *
                    st.push(o1 * o2);
                }
            }
            

        }
        
        return st.top();
    }
};