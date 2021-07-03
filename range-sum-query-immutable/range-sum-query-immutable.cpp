class NumArray {
public:
    
    int n = 0;
    vector<int> sum;
    // vector<int>& loc_nums;
    
    NumArray(vector<int>& nums){
        // this->loc_nums = nums;
        this->n = nums.size();
        this->sum.resize(n+1);
        
        
        for(int i = 0; i < this->n; ++i) {
            sum[i+1] = sum[i] + nums[i];
        }
        
    }
    
    int sumRange(int left, int right) {
        return sum[right+1] - sum[left];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */