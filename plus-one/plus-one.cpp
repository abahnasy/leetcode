class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        vector<int> res;
        for(auto it = digits.rbegin(); it < digits.rend(); ++it) {
            int sum = c + *it;
            if (sum > 9) {
                res.push_back(sum%10);
                sum /=10;
                c = sum;
            } else {
                res.push_back(sum);
                c = 0;
            }
        }
        if( c != 0)
            res.push_back(c);
        
        reverse(res.begin(), res.end());
        return res;
    }
};