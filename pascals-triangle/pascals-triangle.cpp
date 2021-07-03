class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows; ++i) {
            vector<int> loc_v = vector<int>(i+1,1);
            if(i>1) {
                for(int j = 1; j<loc_v.size()-1; ++j) {
                    loc_v[j] = res[i-1][j-1] + res[i-1][j];
                }
            }
            res.push_back(loc_v);
        }
        
        return res;
    }
};