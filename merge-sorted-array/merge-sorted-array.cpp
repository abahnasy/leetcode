class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //copy m into temp_m
        vector<int> temp (m, 0);
        for(int i = 0; i < m; ++i) {
            temp[i] = nums1[i];
        }
        //run pointers over temp_m and n to fill m
        int p = 0;
        int p_m = 0;
        int p_n = 0;
        
        for (int i = 0; i < n+m; ++i) {
            while (p_m < m && p_n < n) {
                // merge
                if (temp[p_m] < nums2[p_n]) {
                    nums1[p] = temp[p_m];
                    ++p;++p_m;
                } else {
                    nums1[p] = nums2[p_n];
                    ++p; ++p_n;
                }
            }
            while (p_m < m) {
                nums1[p] = temp[p_m];
                ++p;++p_m;
            }
            while (p_n < n){
                nums1[p] = nums2[p_n];
                ++p;++p_n;
                
            }    
        }
        
    }
};