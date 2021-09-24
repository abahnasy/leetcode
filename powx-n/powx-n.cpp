class Solution {
public:
    unordered_map<int, double> m;
    double myPow(double x, int n) {
        // cout << "current call: " << n << "\n";
        
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n == -1)
            return 1/x;
        if(m.find(n) != m.end())
            return m[n];
        // int c = (n%2 == 1)? 1:0;
        // cout << "   calling for " << n/2 << " and " << n - int(n/2)<< endl;    
        m[n] = myPow(x, int(n/2)) * myPow(x,n - int(n/2));
        
        return m[n];
    }
};