class Solution {
public:
    
    // TODO: sort_func
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [](vector<int> a, vector<int> b) {
                 return a[0] < b[0];
             }
            );
        
        
        for(auto i: intervals) {
            cout << i[0] << ", " << i[1] << "\n";
        }
        
        // add the first one to the result list
        res.push_back(intervals[0]);
        int res_idx = 0;
        for(int i = 1; i <n; ++i) {
            if(res[res_idx][1] >= intervals[i][0]) {
                res[res_idx][1] = max(res[res_idx][1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
                res_idx++;
            }
        }
        
        
        
        
        return res;
        // sort the main container
        //
        
    }
};