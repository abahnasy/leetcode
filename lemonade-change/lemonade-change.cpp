class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> k;
        for(int i = 0; i < bills.size(); ++i) {
            if(bills[i] == 5){
                k[5]++;
                continue;
            }
            if(bills[i] == 10){
                if(k[5]>0) {
                    k[10]++;
                    k[5]--;
                } else {
                    return false;
                }
                continue;
            }
            if(bills[i] == 20){
                if(k[10] >0 && k[5] >0) {
                    k[10]--;
                    k[5]--;    
                } else if (k[5]>3) {
                    k[5] = k[5] - 3;
                } else {
                    return false;
                }
                continue;
            }
        }
        
        return true;
    }
};

// 5 10
// 10 0
// 20  2  