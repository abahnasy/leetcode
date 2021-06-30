class Solution {
public:
     
    
    
        
    
    int thirdMax(vector<int>& nums) {
        
        long long int max_1 = LONG_MIN;
        long long int max_2 = LONG_MIN;
        long long int max_3 = LONG_MIN;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > max_1) {
                max_3 = max_2;
                max_2 =max_1;
                max_1 = nums[i];
            } else if (nums[i] > max_2 && nums[i] != max_1) {
                max_3 = max_2;
                max_2 = nums[i];
                
            } else if (nums[i] > max_3 && nums[i] != max_2 && nums[i] != max_1) {
                max_3 = nums[i];
            }
        }
        
        return (max_3 > LONG_MIN)? max_3: max_1;
    }
};