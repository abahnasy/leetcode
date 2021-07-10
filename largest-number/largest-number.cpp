class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), 
            [](int a, int b){
                string o1 = to_string(a)+to_string(b);
                string o2 = to_string(b)+to_string(a);
                return o2 < o1;
                
            }
        );
        if(nums[0] == 0)
            return "0";
        stringstream ss;
        for(auto i: nums)
            ss << i;
        string str;
        ss >> str;
        return str;
    }
};