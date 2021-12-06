class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int h_len = (horizontalCuts.size()>=1)? max(horizontalCuts[0], h - horizontalCuts.back()): h;
        // cout << h_len << endl;
        int v_len =(verticalCuts.size() >= 1)? max(verticalCuts[0], w - verticalCuts.back()): w;
        // cout << v_len << endl;
        
        // search for the largets segments
        for(int i = 1; i < verticalCuts.size() ;++i) {
            v_len = max(v_len, verticalCuts[i] - verticalCuts[i-1]);
        }
        
        for(int i = 1; i < horizontalCuts.size() ;++i) {
            h_len = max(h_len, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        // cout << v_len << " " << h_len << endl;
        long int ret =  (1L* h_len * v_len)%(1000000000+7);
        // cout << ret << endl;
        return (int) ret;
    }
};