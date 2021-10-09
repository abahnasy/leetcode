class Solution {
public:
    vector<int> di {-1, 0, 1, 0};
    vector<int> dj {0, 1, 0, -1};
    
    bool bt(vector<vector<char>>& board, 
            vector<vector<bool>>& visited, 
            int i, 
            int j, 
            string& word, 
            int idx)
    {
        if(idx == word.size()) return true;
        if(i < 0 || i >= board.size() || j <0 || j >= board[0].size()) return false;
        // if(visited[i][j]) return false;
        if(board[i][j] != word[idx]) return false;
        // visited[i][j] = true;
        board[i][j] ='0';
        for(int k = 0; k < 4; ++k) {
            if(bt(board, visited, i+di[k], j+dj[k], word, idx+1)) return true;
        }
        // visited[i][j] = false;
        board[i][j] = word[idx];
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int M = board.size();
        int N = board[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(bt(board, visited, i, j, word, 0)) return true;
            }
        }
        
         return false;
    }
    
   
};





/*
 bool rec(board, i, j, word, idx) {
    board[i][j] == word[idx];
    for(n: neighbours)
        
        rec(board @ n, idx+1)
 }











*/