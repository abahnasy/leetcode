class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> p1, vector<int> p2) {
            return p1[1] < p2[1];
        }
        );
        
        // for(auto e: pairs)
        //     cout << e[0] << ", " << e[1] << "\n";
        
        int res = 1;
        int idx = 0; //represents the last valid interval
        for(int i=1; i < pairs.size(); ++i) {
            if(pairs[i][0] > pairs[idx][1]) {
                ++res;
                idx = i;
            }
        }
        return res;
    }
};