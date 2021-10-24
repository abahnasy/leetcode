class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask = 1<<31;
        uint32_t res = 0;
        for(int i = 0; i < 32; ++i) {
            if(n&0x01) res = res | mask;
            n = n>>1;
            mask = mask>>1;
        }
        
        return res;
        
    }
};