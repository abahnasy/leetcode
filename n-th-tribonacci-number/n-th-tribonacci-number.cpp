class Solution {
public:
    int tribonacci(int n) {
        if(n < 2)
            return n;
        if (n == 2)
            return 1;
        
        // vector<int> dp(n+1, 0);
        int dp_1 = 0;
        int dp_2 = 1;
        int dp_3 = 1;
        for(int i = 3; i <= n; ++i) {
            int dp_curr = dp_1 + dp_2 + dp_3;
            dp_1 = dp_2;
            dp_2 = dp_3;
            dp_3 = dp_curr;
        }
        
        
        return dp_3;
        
    }
};