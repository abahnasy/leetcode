class Solution {
public:
    
    bool check_validity(vector<vector<int>>& grid, int curr_i, int curr_j, int n) {
        // check col
       
        for(int i = 0; i < n, i != curr_i; ++i) {
            if(grid[i][curr_j] == 1) {
                return false;
            }
        }
        // check row
        for(int j = 0; j < n, j != curr_j; ++j) {
            if(grid[curr_i][j] == 1) {
                return false;
            }
        }
        // check diag
        for(int i = curr_i+1, j = curr_j+1; i<n && j<n; ++i,++j) {
            if(grid[i][j] == 1) {
                return false;
            }
        }
        for(int i = curr_i-1, j = curr_j-1; i >= 0 && j>=0; --i,--j) {
            if(grid[i][j] == 1) {
                return false;
            }
        }
        
        for(int i = curr_i+1, j = curr_j-1; i < n && j>=0; ++i,--j) {
            if(grid[i][j] == 1) {
                return false;
            }
        }
        for(int i = curr_i-1, j = curr_j+1; i >= 0 && j<n; --i,++j) {
            
            if(grid[i][j] == 1) {
                return false;
            }
        }
        
        return true;
    }
    
    void bt(vector<vector<string>>& res, vector<vector<int>>& grid, int curr, int n) {
        // base condition
        if(curr == n) {
            // cout  << "reached sol !\n";
            vector<string> v;
            for(int i = 0; i < n; ++i) {
                stringstream ss;
                for(int j = 0; j < n ; ++j) {
                    if(grid[i][j] == 1) {
                        ss << "Q";
                    }
                    else{
                        ss << ".";
                    }
                }
                v.push_back(ss.str());
            }
            res.push_back(v);
            return;
        }
        // for(int i = curr; i < n; ++i) {
            for(int j = 0; j < n ; ++j) {
                grid[curr][j] = 1;
                if(check_validity(grid, curr, j, n)) {
                    // proceed further
                    bt(res, grid, curr+1, n);
                }
                grid[curr][j] = 0;
            }
        // }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<int>> grid(n, vector<int>(n,0)); // 0: free 1: queen
        
        bt(res, grid, 0, n);
        
        return res;
    }
};