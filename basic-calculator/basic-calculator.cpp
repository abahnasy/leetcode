class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sum = 0;
        int num = 0;
        int sgn = 1; // 1 or -1
        for(int i = 0; i < s.size(); ++i) {
            // 5 cases
            if(s[i] >= '0' && s[i] <= '9') {
                num = num*10 + int(s[i] - '0'); //conversion from string to int
            } else if (s[i] == '+') {
                sum += num*sgn;
                sgn = 1;
                num = 0;
            } else if (s[i] == '-') {
                sum += num*sgn;
                sgn = -1;
                num = 0;
            } else if (s[i] == '(') {

                st.push(sum);
                st.push(sgn);
                // reset containers
                sum = 0;
                sgn = 1;

            } else if (s[i] == ')') {
                sum += num*sgn;
//                sgn = 1;
                num = 0;
                int temp_sgn = st.top();
                st.pop();
                int temp_val = st.top();
                st.pop();
                sum = temp_sgn*sum + temp_val;


            }
        }


        return sum += num*sgn;
    }
};