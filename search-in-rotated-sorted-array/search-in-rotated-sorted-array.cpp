class Solution {
public:
    int bsearch(int& target, vector<int>& nums, int l, int r) {
        // cout << "calling with left: " << l << ", right: " << r << "\n";
        if(r >= l) {
            int m = l + (r-l)/2;
            if(nums[m] == target) 
                return m;
            int l_call = bsearch(target, nums, l, m-1);
            if(l_call != -1) 
                return l_call;
            int r_call = bsearch(target, nums, m+1, r);
            if(r_call != -1)
                return r_call;
        }
            return -1;
        
    }
    int search(vector<int>& nums, int target) {
        return bsearch(target, nums, 0, nums.size()-1);
    }
};