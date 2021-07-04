class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int r1 = 0; int r2 = matrix.size()-1;
        int c1 = 0; int c2 = matrix[0].size()-1;
        
        vector<int> res;
        
        while (r1 <= r2 && c1 <= c2) {
            cout << "1: " << endl;
            for(int c = c1; c <= c2; ++c){
                res.push_back(matrix[r1][c]);
                cout << matrix[r1][c] << ", ";
            }
            cout << endl;
            
            cout << "2: " << endl;
            for(int r = r1+1; r <= r2; ++r) {
                res.push_back(matrix[r][c2]);
                cout << matrix[r][c2] << ", ";
            }
            cout << endl;
            if(r1 < r2 && c1 < c2) {
                
            
            cout << "3: " << endl;
            for(int c = c2-1; c > c1; --c) {
                res.push_back(matrix[r2][c]);
                cout << matrix[r2][c] << ", ";
            }
            cout << endl;
            
            cout << "4: " << endl;
            for(int r = r2; r >r1; --r) {
                res.push_back(matrix[r][c1]);
                cout << matrix[r][c1] << ", ";
            }
            cout << endl;
            }
        
    
        
        
        ++r1;
        --r2;
        ++c1;
        --c2;
        
        }

        return res;
    }
};