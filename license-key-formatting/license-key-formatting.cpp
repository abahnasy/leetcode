class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        stack<char> st;
        for(char c: s) {
            if (c != '-')
                st.push(toupper(c));
        }
        int c = 0;
        vector<char> ss;
        while(!st.empty()) {
            ss.push_back(st.top());
            st.pop();
            ++c;
            if(c == k && !st.empty()) {
                ss.push_back('-');
                c = 0;
            }
        }
        string res;
        for(auto itr = ss.rbegin(); itr != ss.rend(); ++itr) {
            res += *itr;
        }
        
        return res;
        
    }
};