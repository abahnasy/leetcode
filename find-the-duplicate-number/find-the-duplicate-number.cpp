class Solution {
public:
    
    int linear_search(vector<int>& nums, int x) {
        int c = 0;
        for (auto n: nums) {
            if (n <= x)
                ++c;
        }
        return c;
    }
    
    int findDuplicate(vector<int>& nums) {
        int l = 1;
        int r = nums.size()-1;
        
        while(l < r) {
            int mid = l + (r-l)/2;
            int no_less_equal = linear_search(nums, mid);
            if(no_less_equal > mid) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        
        return l;
    }
};