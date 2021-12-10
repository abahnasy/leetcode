class Solution {
public:
    int solve(int house, vector<int>& heaters) {
        int l = 0;
        int r = heaters.size()-1;
        
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(house == heaters[mid])
                return 0;
             else if (house > heaters[mid]) {
                l = mid+1;
            } else if (house < heaters[mid]) {
                r = mid-1;
            }
        }
        
        return min(house -heaters[r], heaters[l] - house);
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int rad = 0;
        sort(heaters.begin(), heaters.end());
        for (int house: houses) {
            if (house <= heaters.front()) {
                rad = max(rad, heaters.front()- house);
                continue;
            }
                
        
            if (house >= heaters.back()) {
                rad =max(rad,  house - heaters.back());
                continue;
            }
                
            int ret = solve(house, heaters);
            rad = max(rad, ret);
        }
        
        return rad;
    }
};