class Solution {
public:
    bool canJump(vector<int>& nums) {
        // check every position is reachable by any of its previous positions
        for(int i = 1; i < nums.size() ;++i) {
            bool f = false;
            for(int j = i-1; j >=0; --j) {
                if (nums[j]>= i-j) {
                    f = true;
                    break;
                }
            }
            if (!f)
                return false;
        }
        return true;
    }
};