class Solution {
public:
    unordered_map<int, int> m;
    int query(unordered_map<int, int>&m, int i) {
        if(m.find(i)!= m.end()) return m[i];
        else return 0;
    }
    int deleteAndEarn(vector<int>& nums) {
        for(auto n: nums) {
            m[n] += n;
        }
        vector<int> dp(10001, 0);
        dp[1] = query(m, 1);
        for(int i = 2; i < 10001; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + query(m, i));
        }
        
        return dp[10000];
    }
};

//              |
// [2,2,3,3,3,4,5,5,6]
// [2,4,4,6,9,8,19,15]

// 2-> 4
// 3-> 9
// 4-> 4
// 5-> 10
// 6-> 6

// [4,9, 9, 19, 19 ]