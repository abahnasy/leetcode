class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        
        for(auto c:moves) {
            // R = x++
            // L = x--
            //U = y++
            //D = y--
            if(c == 'R') x++;
            if(c == 'L') x--;
            if(c == 'U') y--;
            if(c == 'D') y++;
        }
        
        return (x == 0 && y==0);
    }
};