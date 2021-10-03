class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0; int r = 0;
        int steps = 0;
        while(r < nums.size()-1) {
            // cout << "range: " << l << ", " << r << "\n";
            int max_r = 0;
            for(int i = l; i <= r; ++i) {
                max_r = max(max_r, i + nums[i]);
                // cout << "done\n";
            }
            ++steps;
            l = r+1;
            r = max_r;
        }
        
        return steps;
        
    }
};