class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        vector<int>dp(n, INT_MAX); 
        dp[0]= 0;
        
        for(int i = 1; i < n; ++i ){
            // bool reachable = false;
            for(int j = i-1; j >= 0; --j) {
                if(i - j <= nums[j]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                    // reachable = true;
                    // break;
                }
            }
            // if(!reachable) return false;
        }
        
        return dp[n-1];
    }
    
};

/*
dp: [0,1,1,2,2]
    [2,3,1,1,4]



*/