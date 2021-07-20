class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int N = nums.size();
        int k = 0;
        int i = 0;
         while(i < N) {
             if(nums[i] == val) {
                 nums[i] = nums[N-1];
                --N;
             } else {
                 ++i;
             }
                 
         }
        
        return N;
        
        
    }
};