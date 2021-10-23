class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        while(n) {
            if(n&0x01)++c;
            n = n>>1;
        }
        return c;
        
    }
};