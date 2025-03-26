class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int r = grid.size();
        int c = grid[0].size();
        int m = grid[0][0] % x;
        vector<int> v(r * c);
        for (int i = 0; i < r; ++ i) {
            for (int j = 0; j < c; ++ j) {
                if ((grid[i][j] % x) != m)
                    return -1;
                v[(i * c) + j] = grid[i][j];
            }
        }
        ranges::sort(v);
        int t = v[(r * c) >> 1];
        int res = 0;
        for (int i = 0; i < (r * c); ++ i)
            res += abs(v[i] - t) / x;
        return res;
    }
};
