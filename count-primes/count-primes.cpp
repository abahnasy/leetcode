class Solution {
public:
    int countPrimes(int n) {
        if(n<= 1) return 0;
        vector<bool> db(n, true);
        db[0] = false;
        db[1] = false;
        for(int i = 2 ; i*i<n;++i) {
            if(db[i]) {
                for(int k = i*i; k <n; k = k+i) {
                    db[k]  = false;
                }
            }
        }
        int c = 0;
        for(auto e: db) {
            if(e)++c;
        }
        
        return c;
    }
};