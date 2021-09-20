typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vector<int>> vii;


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int N = intervals.size();
        vii res;
        int i = 0;
        while(i < N && intervals[i][1] < newInterval[0]) {
            // add non overlapping before
            res.push_back(intervals[i++]);
        }
        
        while (i < N && intervals[i][0] <= newInterval[1] ) {
            // expand the interval according to the overlapping
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.push_back(newInterval);
        
        while(i<N) {
            // add the rest
            res.push_back(intervals[i++]);
        }
        
        return res;
        
    }
};