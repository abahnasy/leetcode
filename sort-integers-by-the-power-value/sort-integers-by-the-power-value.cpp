// bool comparator(pair<int, int> l, pair<int, int> r) {
//     return (l.second < r.second) ;
        
// }

class Solution {

public:
    int get_power(int n, unordered_map<int, int>& m) {
        if(n == 1) return 0;
        if(m.count(n)>0) return m[n];
        if(n%2 == 0)
            m[n] = 1 + get_power(n/2, m);
        else
            m[n] = 1 + get_power(3*n+1, m);
        
        return m[n];
            
    }
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> m;
        vector<pair<int, int>> rank; // pair<int, int> is number, rank
        for(int i = lo; i <= hi; ++i) {
            rank.push_back({get_power(i, m) ,i});
        }
        sort(rank.begin(), rank.end());
        
        return rank[k-1].second;
    }
};