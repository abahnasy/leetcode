class Solution {
public:
    bool valid_cap(vector<int>& weights, int capacity, int days) {
        int count = 0;
        int curr_w = 0;
        for(auto w: weights) {
            if(w>capacity) return false;
            if(curr_w + w <= capacity)
                curr_w += w;
            else {
                ++count;
                curr_w = w;
            }
        }
        if(count != capacity)++count;
        return (count<= days)?true:false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int _max = 0;
        for(auto e: weights) _max += e;
        int l = 1;
        int r = _max;
        int last_valid = _max;
        while(l<=r) {
            int mid = l + (r-l)/2;
            cout << "bin search, left: " << l <<" mid: " << mid << " right: " << r << "\n"; 
            if(valid_cap(weights, mid, days)) {
                last_valid = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return last_valid;
    }
};

//                     |
// [1,2,3,4,5,6,7,8,9,10], cap = 15;
// curr_w = 10
// count = 4