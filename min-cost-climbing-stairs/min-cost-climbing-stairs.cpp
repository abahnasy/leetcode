class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2) {
            return (cost[0] > cost[1])? cost[1]: cost[0];
        } else {
            for (int i =2; i < cost.size(); ++i) {
                cost[i] += min(cost[i-1], cost[i-2]);
            }
            
            return min(cost[cost.size()-1], cost[cost.size()-2]);
        }
    }
};


// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         // reverse solution starting from the end
//         // this might be useful in case cost array is not editable
//         int step1 = 0;
//         int step2 = 0;
//         for(int i= cost.size()-1; i>=0;--i) {
//             int curr_step = cost[i] + min(step1, step2);
//             step1=step2;
//             step2=curr_step;
//         }
//         return min(step1, step2);
            
//     }
// };