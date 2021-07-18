class Solution {
public:
    struct compare {
       bool operator() (pair<int, int> lhs, pair<int, int> rhs) {
           return (lhs.first + lhs.second) > (rhs.first + rhs.second);
       }  
    };
    
    priority_queue<pair<int , int>, vector<pair<int ,int>>, compare> pq;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        for(int i = 0; i < nums1.size(); ++i) {
            for(int j = 0; j < nums2.size(); ++j ) {
                pq.push({nums1[i], nums2[j]});
            }
        }
        
        vector<vector<int>> res;
        for( int i = 0; i < k ; ++i) {
            if(pq.empty())
                break;
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
            
        }
        
        
        return res;
        
    }
};