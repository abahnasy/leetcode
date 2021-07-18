class Solution {
public:

    struct compare {
        bool operator() (tuple<int, int, int> lhs, tuple<int, int, int> rhs) {
            auto [le, lr, lc] = lhs;
            auto [re, rr, rc] = rhs;


            return le > re;
        }
    };

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, compare> pq;

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // push the elements in the first row to the pq
        int N = matrix.size();
        for(int i =0; i < N ; ++i) {
            pq.push({matrix[0][i], 0, i});
        }

        // repeat for k-1 steps
        for(int i = 0; i < k-1 ; ++i) {

            int val = get<0>(pq.top());
            int row = get<1>(pq.top());
            int col = get<2>(pq.top());
            pq.pop();
            if(++row < N)
                pq.push(make_tuple(matrix[row][col], row, col));
        }



        auto [e, row, col] = pq.top();
        return  e;
    }
};