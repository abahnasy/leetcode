class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        while(l < r) {
            // cout << " l and r " << l << ", " << r << "\n";
            long mid = (r+ l)/2;
            if (mid*mid == x) {
                return mid;
                
            } else if (mid*mid > x) {
                r = mid -1;
            } else {
                if((mid+1)*(mid+1)>x)
                    return mid;
                l = mid+ 1;
            }
        }
        
        return l;
        
    }
};