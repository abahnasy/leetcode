class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int i = 32;
        while(i) {
            // extract the least bit
            uint32_t bit = n & 0x01;
            res = res << 1;
            res = res | bit;
            n = n>>1;
            //shift res
            // add it to res
            --i;
        }
        
        return res;
    }
};