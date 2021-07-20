class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void moveZeroes(vector<int>& nums) {
        for(int z = 0, i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) {
                swap(nums, z, i);
                ++z;
            }
            
        }
    }
};