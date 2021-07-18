class Solution {
public:
    struct compare {
        bool operator() (tuple<int, int, int> lhs, tuple<int, int, int> rhs) {
            auto [le, lr, lc] = lhs;
            auto [re, rr, rc] = rhs;


            return le > re;
        }
    };
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, compare> pq;
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        
        for(int i = 0; i < nums1.size(); ++i) {
            pq.push({nums2[0] + nums1[i], i, 0});
        }
        
        
        for(int i = 0; i < k ; ++i) {
            if(pq.empty()) {
            break;
            }
            int val = get<0>(pq.top());
            int l1 = get<1>(pq.top());
            int l2 = get<2>(pq.top());
            res.push_back({nums1[l1],nums2[l2]});
            pq.pop();
            if(++l2 < nums2.size())
                pq.push({nums1[l1] + nums2[l2], l1, l2});
        }

        
        
        return res;
        
    }
};




// class Solution {
// public:
//     struct compare {
//        bool operator() (pair<int, int> lhs, pair<int, int> rhs) {
//            return (lhs.first + lhs.second) > (rhs.first + rhs.second);
//        }  
//     };
    
//     priority_queue<pair<int , int>, vector<pair<int ,int>>, compare> pq;
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
//         for(int i = 0; i < nums1.size(); ++i) {
//             for(int j = 0; j < nums2.size(); ++j ) {
//                 pq.push({nums1[i], nums2[j]});
//             }
//         }
        
//         vector<vector<int>> res;
//         for( int i = 0; i < k ; ++i) {
//             if(pq.empty())
//                 break;
//             res.push_back({pq.top().first, pq.top().second});
//             pq.pop();
            
//         }
        
        
//         return res;
        
//     }
// };