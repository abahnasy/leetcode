class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m {{0,1}};
        int N = nums.size();
        int c = 0;
        int sums = 0;
        for(int e: nums) {
            sums += e;
            c += m[sums -k];
            m[sums]++;
            
        }
        return c;
        
    }
};