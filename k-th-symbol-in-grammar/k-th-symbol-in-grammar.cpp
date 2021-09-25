class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        bool left = (k%2 == 1)? true: false;
        
        int parent = kthGrammar(n-1, (left)?k/2+1:k/2);
        if(parent)
            return (left)?1:0;
        return (left)?0:1;
    }
};