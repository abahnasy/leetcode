class Solution {
public:
    int min_part(vector<int>& nums, int l, int r) {
        // cout << "l and r " << l << ", " << r << "\n"; 
        if(l>r) return INT_MAX;
        if(l == r) return nums[l];
        int m = l + (r-l)/2;
        int m1 = min_part(nums, l, m-1);
        int m2 = min_part(nums, m+1, r);
        // cout << "comparing: " << m << ", " << m1 << ", " << m2 << "\n";
        return min({nums[m], m1, m2});
        
        
    }
    int findMin(vector<int>& nums) {
       return min_part(nums, 0, nums.size()-1);
    }
};

// [1,2,3,4,5,6,7,0]

// m @ 3