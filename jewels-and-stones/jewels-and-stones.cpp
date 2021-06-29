// class Solution {
// public:
//     int numJewelsInStones(string jewels, string stones) {
//         int c = 0;
//         for(int i = 0; i < stones.length(); ++i) {
//             for(int j = 0; j < jewels.length(); ++j) {
//                 if (stones[i] == jewels[j]) {
//                     ++c;
//                 }
//             }
//         }
//         return c;
//     }
// };

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int c = 0;
        
        // create map to jewels
        map<int, bool> m;
        for (int i = 0; i < jewels.length();++i) {
            m[jewels[i]] = 1;
        }
        
        for(int j = 0; j < stones.length(); ++j) {
            if(m.find(stones[j]) != m.end())
                ++c;
        }
        
        
        return c;
    }
};