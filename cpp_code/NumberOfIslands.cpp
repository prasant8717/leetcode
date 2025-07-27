class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int res = 0;
        int d[5] = {-1, 0, 1, 0, -1};
        function<void(int, int)> islands = [&](int i, int j) {
            grid[i][j] = '0';
            for (int k = 0; k < 4; ++ k) {
                int x = i + d[k];
                int y = j + d[k + 1];
                if ((x >= 0) && x < grid.size() &&
                    (y >= 0) && y < grid[0].size() &&
                    (grid[x][y] == '1')) {
                    islands(x, y);
                }
            }
        };
        for (int i = 0; i < r; ++ i) {
            for (int j = 0; j < c; ++ j) {
                if (grid[i][j] == '1') {
                    islands(i, j);
                    ++ res;
                }
            }
        }
        return res;        
    }
};
