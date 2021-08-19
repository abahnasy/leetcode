class Solution {
public:





    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
  
        vector<int> res(queries.size(), 0);
        unordered_map<int, unordered_set<int>> lamps_loc;
        unordered_map<int, int> row;
        unordered_map<int, int> col;
        unordered_map<int, int> a_d;
        unordered_map<int, int> d_d;
        // grid.resize(n , vector<int>(n, 0));
        // lamp_grid.resize(n, vector<bool>(n, false));

        for(auto lamp: lamps) {
            
            if(lamps_loc[lamp[0]].insert(lamp[1]).second) {
                ++row[lamp[0]];
                ++col[lamp[1]];
                ++a_d[lamp[0]+lamp[1]];
                ++d_d[lamp[0]-lamp[1]];
            }
        }
        vector<int> dir_i = {0, -1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dir_j = {-1, -1, 0, 1, 1 ,1 , 0, -1, 0};
        for(int i = 0; i < queries.size(); ++i) {
            int pos_i = queries[i][0];
            int pos_j = queries[i][1];
            if(row[pos_i] || col[pos_j] || a_d[pos_i +pos_j] || d_d[pos_i-pos_j]) {
                res[i] = 1;
                // loop for available lamps
                for(int k = 0; k < 9;++k ) {
                    int curr_i = pos_i+ dir_i[k];
                    int curr_j = pos_j+ dir_j[k];
                     if(curr_i < 0 || curr_i >= n || curr_j < 0 || curr_j >= n)
                         continue;
                    if(lamps_loc[curr_i].find(curr_j)!= lamps_loc[curr_i].end()) {
                        lamps_loc[curr_i].erase(curr_j);
                        --row[curr_i];
                        --col[curr_j];
                        --a_d[curr_i + curr_j];
                        --d_d[curr_i - curr_j];
                        
                    }
                
                }
                
            } else {
                res[i] = 0;
            }
            
            
            
        }

        return res;


    }
};