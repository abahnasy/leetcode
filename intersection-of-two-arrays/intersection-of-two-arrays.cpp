class Solution {
public:
//     vector<int> intersect(unordered_set<int>& s1, unordered_set<int>& s2) {
//         // loop over the small one
//         vector<int> res;
//         for(int e: s1) {
//             if(s2.find(e) != s2.end()) {
//                 res.push_back(e);
//             }
//         }
        
//         return res;
//     }
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         //
//         // unordered_map<int, bool>m1;
//         // unordered_map<int, bool>m2;
//         unordered_set<int> s1;
//         unordered_set<int> s2;
        
//         for(int e: nums1) {
//             s1.insert(e);
//         }
//         for(int e: nums2) {
//             s2.insert(e);
//         }
        
// //         for(int e: nums1)
// //             m1[e] = true;
        
// //         for(int e: nums2)
// //             m1[e] = true;
        
//         if(s1.size() < s2.size()) {
//             return intersect(s1,s2);
//         } else {
//             return intersect(s2, s1);
//         }
//     }
    
    vector<int> intersect(vector<int>& l1, vector<int>& l2 ) {
        // sorted lists assumption
        sort(l1.begin(), l1.end());
        // cout << "sorted arrays are \n";
        // for(int e: l1)
        //     cout << e << ", ";
        // cout << "\n";
        // for(int e: l2)
        //     cout << e << ", ";
        // cout << "\n";
        
        sort(l2.begin(), l2.end());
        int i1 = 0;
        int i2 = 0;
        vector<int> res;
        while(i1 < l1.size() && i2 < l2.size()) {
            // cout << "checking " << i1 << ", " << i2 << "\n";
            int t1 = l1[i1]; 
            int t2 = l2[i2];
            
            if(t1 == t2) {
                res.push_back(t1);
                // skip duplicates
                while(i1 < l1.size() && l1[i1] == t1) 
                    ++i1;
                while(i2 < l2.size() && l2[i2] == t2) 
                    ++i2;
                // cout << " final values of the indices are " << i1 << ", " << i2 << "\n";
                
            } else if(t1 < t2) {
                ++i1;
            } else {
                ++i2;
            }
                
        }
        
        return res;
        
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       return intersect(nums1, nums2);
    }
};