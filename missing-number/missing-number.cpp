class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        int n = nums.size()+1;
        for(int i = 1; i < n; ++i) {
            total += i;
        }
        for(int n: nums){
            total -= n;
        }
            
        return total;
    }
};