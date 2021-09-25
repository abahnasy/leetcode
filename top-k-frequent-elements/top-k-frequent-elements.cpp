typedef pair<int,int> pii;

struct comparator {
  bool operator()(pii a, pii b) {
                 return a.second < b.second;
             }
};
class Solution {
public:
    //TODO: define the comparator
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto n: nums) {
            if(m.find(n) == m.end())
                m[n] = 1;
            else
                m[n]++;
        }
        
        // auto f =  [](pii a, pii b) {
        //          return a.second < b.second;
             // };
        priority_queue<pii, vector<pii>, comparator> pq;
        for(auto itr = m.begin(); itr != m.end(); ++itr) {
            pq.push({itr->first, itr->second});
        }
        
        vector<int> res;
        for( int i = 0; i < k; ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
    }
};