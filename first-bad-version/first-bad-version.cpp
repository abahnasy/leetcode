// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(mid != 0 && 
               isBadVersion(mid) == true && 
               isBadVersion(mid-1) == false) 
            {
                return mid;
                
            } else if (isBadVersion(mid) == true) {
                r = mid -1;
            } else {
                l = mid+1;
            }
        }
        
        return l;
    }
};

