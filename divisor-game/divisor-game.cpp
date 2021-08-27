// class Solution {
// public:
//     bool divisorGame(int N) {
//         if (N == 1)
//             return false;
//         for(int i = 1; i < N; ++i) {
//             if ((N%i == 0) && divisorGame(N-i) == false)
//                 return true;
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     int dp [1001];
//     bool divisorGame(int N) {
//         memset(dp, -1, sizeof dp);
//         if (N == 1)
//             return false;
//         for(int i = 1; i*i < N; ++i) {
//             if (N%i == 0) {
//                 if (dp[N-i] == -1) {
//                     dp[N-i] = divisorGame(N-i);
//                 }  
//                 if (dp[N-i] == 0) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool divisorGame(int N) {
       if (N%2==0) return true;
        return false;
    }
};