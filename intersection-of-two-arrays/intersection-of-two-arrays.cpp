class Solution {
public:
    vector<int> intersect(unordered_set<int>& s1, unordered_set<int>& s2) {
        // loop over the small one
        vector<int> res;
        for(int e: s1) {
            if(s2.find(e) != s2.end()) {
                res.push_back(e);
            }
        }
        
        return res;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //
        // unordered_map<int, bool>m1;
        // unordered_map<int, bool>m2;
        unordered_set<int> s1;
        unordered_set<int> s2;
        
        for(int e: nums1) {
            s1.insert(e);
        }
        for(int e: nums2) {
            s2.insert(e);
        }
        
//         for(int e: nums1)
//             m1[e] = true;
        
//         for(int e: nums2)
//             m1[e] = true;
        
        if(s1.size() < s2.size()) {
            return intersect(s1,s2);
        } else {
            return intersect(s2, s1);
        }
    }
};