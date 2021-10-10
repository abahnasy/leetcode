class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0) {
            return 0;
        }
        int move_factor = 1;
        while(left != right) {
            left = left >> 1;
            right = right >> 1;
            move_factor = move_factor <<  1;
        }
        
        return left * move_factor;
        
    }
};