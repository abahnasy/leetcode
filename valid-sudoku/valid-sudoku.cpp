class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,  int>m;
       
        // validate rows
        for(int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if(board[i][j] != '.' && m[board[i][j]] == 1) {
                    cout << "invalid col " << i << endl;
                    cout << " value is " << m[board[i][j]] << endl;
                    return false;
                }
                m[board[i][j]] = true;
                
            }
            m.clear();
        }
        // validate cols
        for(int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if(board[j][i] != '.' && m[board[j][i]] == 1) {
                    cout << "invalid row " << i << endl; 
                    return false;
                }
                m[board[j][i]] = true;
                
            }
            m.clear();
        }
        // validate sub arrays
        
     
        for(int start_row = 0; start_row < 9; start_row=start_row+3) {
            for(int start_col = 0; start_col < 9; start_col=start_col+3) {
                for(int i = start_row; i < start_row+3; ++i) {
                    for(int j = start_col; j < start_col+3; ++j) {
                        if(board[i][j] != '.' && m[board[i][j]] == 1) {
                            cout << "invalid box " << start_row << ", " << start_col << endl; 
                            return false;
                        }
                        m[board[i][j]] = true;
                    }
                }
                
                m.clear();
                
                
            }
            
        }
        
        
        
        return true;
    }
};

// 0 0
// 0 3
// 0 6
// 3 0
// 3 3
// 3 6
// 6 0
// 6 3
// 6 6