class Solution {
public:
    int binsearch(vector<int>& nums, int& target, int l, int r) {
        // cout << "call with: " << l << " and " << r << "\n";
        if(r >= l) {
            int m = l + (r-l)/2;
            if(nums[m] == target) return m;
            else if (nums[m]< target) return binsearch(nums, target, m+1, r);
            else return binsearch(nums,target, l, m-1);
        }
        // it should be here
        return l;
    }
    int searchInsert(vector<int>& nums, int target) {
        return binsearch(nums, target, 0, nums.size()-1);
    }
};