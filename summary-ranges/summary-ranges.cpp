class Solution {
public:
    
    string get_string(int s, int f) {
        stringstream ss;
        if(s != f) {
            ss << s << "->" << f;
        } else {
            ss << s;
        }
    
        return ss.str();
        
    }
    vector<string> summaryRanges(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) {
            return vector<string>();
        }
        vector<string> res;
        int s = 0;
        
        for(int i = 1; i < N; ++i) {
            if(nums[i-1] +1 != nums[i]) {
                res.push_back(get_string(nums[s], nums[i-1]));
                s = i;
                
            }
        }
        
        res.push_back(get_string(nums[s], nums[N-1]));
        
        
        
        return res;
    }
};