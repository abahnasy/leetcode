class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()-k];
        
        priority_queue<int> pq;
        for(auto e : nums) {
            pq.push(e);
        }
        for(int i = 1; i < k; ++ i) {
            pq.pop();
        }
        return pq.top();
    }
};