class Solution {
public:
    // check neighbours -> return boolean of live neighbours
    int live_n(vector<vector<int>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();
        vector<int> dr {0,-1,-1,-1,0,1,1,1};
        vector<int> dc {1,1,0,-1,-1,-1,0,1};
        int res = 0;
        int curr_r =0;
        int curr_c =0; 
        for(int i=0; i < 8; ++i) {
            curr_r = r + dr[i];
            curr_c = c + dc[i];
            if (curr_r>= 0 && curr_r < m && curr_c >= 0 && curr_c < n) {
                if (board[curr_r][curr_c] == 1)
                    ++res;
            }
        }
        
        return res;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        // copy board
        vector<vector<int>> temp(board.size(), vector<int>(board[0].size()));
        for(int i = 0; i < board.size(); ++ i) {
            for(int j = 0; j < board[0].size(); ++j) {
                temp[i][j] = board[i][j];
            }
        }
        // loop over every element
        for(int i = 0; i < board.size(); ++ i) {
            for(int j = 0; j < board[0].size(); ++j) {
                int stat = board[i][j];
                int l_n = live_n(board, i, j);
                // given the status and neigbours, apply condiditon 
                // in the copies one
                if(stat) {
                    if (l_n < 2 || l_n > 3)
                        temp[i][j] = 0;
                } else {
                    if (l_n == 3)
                        temp[i][j] = 1;
                }
            }
        }
        
        // refer to the copied one
        for(int i = 0; i < board.size(); ++ i) {
            for(int j = 0; j < board[0].size(); ++j) {
                board[i][j] = temp[i][j];
            }
        }
        
    }
};