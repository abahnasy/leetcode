class Solution {
public:
    // bool paland(string s) {
    //     int n = s.size();
    //     if (n == 1)
    //         return true;
    //     for(int i =0; i < n/2; ++i) {
    //         if (s[i] != s[n-1-i])
    //             return false;
    //     }
    //     return true;
    // }
    // int countSubstrings(string s) {
    //     // cout << s.substr(1,2) << endl;
    //     int n = s.size();
    //     int count = 0;
    //     for( int i = 0;i < n;++i) {
    //         for(int j = 1; j <= n-i; ++j) {
    //             string curr = s.substr(i, j);
    //             // cout << "i,j, curr: " <<i<<" "<<j<<" "<< curr << endl;
    //             if(paland(curr))
    //                 ++count;
    //         }
    //     }
    //     return count;
    // }
    int res = 0;
    void expand_from_center(string s, int i, int j) {
        while(i >= 0 && j <s.size()) {
            if(s[i] == s[j]) {
                res++;i--;j++;
            } else {
                break;
            }
                
            
        }
    }
    int countSubstrings(string s) {
        // more optimized approach !
        for(int i = 0; i < s.size(); ++i) {
            // odd case
            expand_from_center(s, i,i);
            // even case
            expand_from_center(s, i,i+1);
        }
       
        return res;
    }
};