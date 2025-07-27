class Solution {
public:
    int count(vector<vector<int>>& g, int i, int j) {
        int m = g.size();
        int n = g[0].size();
        int t = g[i][j];
        g[i][j] = 0;
        int ds[5] = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++ k) {
            int r = i + ds[k];
            int c = j + ds[k + 1];
            if ((r >= 0) && (r < m) &&
                (c >= 0) && (c < n) &&
                (g[r][c] != 0))
                t += count(g, r, c);
        }
        return t;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] != 0) {
                    int t = count(grid, i, j);
                    if (res < t)
                        res = t;
                }
            }
        }
        return res;
    }
};
