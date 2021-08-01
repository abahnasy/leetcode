class Solution {
public:
    int M = 0;
    int N = 0;

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0,1}};

    int dfs(vector<vector<int>>& grid, int i, int j, int island_id) {
        if(i < 0 || j < 0 || i >= M || j >= N || grid[i][j] != 1)
            return 0;

        grid[i][j] = island_id;

        int count = 1;
        for(int d = 0; d < dir.size(); ++d) {
            count += dfs(grid, i+dir[d][0], j + dir[d][1], island_id);
        }
        // call neighbours
        // return total size

        return count;

    }

    int largestIsland(vector<vector<int>>& grid) {
        int max_size = 0;
        M = grid.size();
        N = grid.size();
        int island_id = 2;
        unordered_map<int, int> m;


        // first loop to create the islands ids
        for(int i = 0 ;i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if(grid[i][j] == 1) {
                    int size = dfs(grid, i, j, island_id);
                    max_size = max(max_size, size);
                    m[island_id++] = size;
                }

            }
        }

        // second loop to check connections
        for(int i = 0 ;i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if(grid[i][j] == 0) {
                    set<int> neigh_ids;
                    for(int d = 0; d < dir.size(); ++d) {
                        int new_i = i+dir[d][0];
                        int new_j = j+dir[d][1];
                        if(new_i < 0 || new_j < 0 || new_i >= M || new_j >= N)
                            continue;
                        neigh_ids.insert(grid[new_i][new_j]);
                    }

                    int size = 1;
                    for(auto e: neigh_ids)
                        size += m[e];
                    max_size = max(max_size, size);
                }
            }
        }

        return max_size;



    }
};