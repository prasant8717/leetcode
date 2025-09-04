class Solution {
private:
    int min_area(vector<vector<int>>& grid,
                int si, int ei, int sj, int ej) {
        int a1 = INT_MAX;
        int b1 = INT_MAX;
        int a2 = 0;
        int b2 = 0;
        for (int i = si; i <= ei; ++ i)
            for (int j = sj; j <= ej; ++ j)
                if (grid[i][j] == 1) {
                    if (a1 > i)
                        a1 = i;
                    if (b1 > j)
                        b1 = j;
                    if (a2 < i)
                        a2 = i;
                    if (b2 < j)
                        b2 = j;
                }
        return a1 == INT_MAX ? 0 : (a2 - a1 + 1) * (b2 - b1 + 1);
    }

public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = m * n;
        for (int i = 0; i < m; ++ i) {
            int t = min_area(grid, 0, i, 0, n - 1);
            for (int j = 0; j < n; ++ j)
                res = min(res, t + min_area(grid, i + 1, m - 1, 0, j) +
                    min_area(grid, i + 1, m - 1, j + 1, n - 1));
        }
        for (int i = 0; i < m; ++ i) {
            int t = min_area(grid, i, m - 1, 0, n - 1);
            for (int j = 0; j < n; ++ j)
                res = min(res, t + min_area(grid, 0, i - 1, 0, j) +
                    min_area(grid, 0, i - 1, j + 1, n - 1));
        }
        for (int j = 0; j < n; ++ j) {
            int t = min_area(grid, 0, m - 1, 0, j);
            for (int i = 0; i < m; ++ i)
                res = min(res, t + min_area(grid, 0, i, j + 1, n - 1) +
                    min_area(grid, i + 1, m - 1, j + 1, n - 1));
        }
        for (int j = 0; j < n; ++ j) {
            int t = min_area(grid, 0, m - 1, j, n - 1);
            for (int i = 0; i < m; ++ i)
                res = min(res, t + min_area(grid, 0, i, 0, j - 1) +
                    min_area(grid, i + 1, m - 1, 0, j - 1));
        }
        for (int i = 0; i < m; ++ i)
            for (int j = i + 1; j < m; ++ j)
                res = min(res, min_area(grid, 0, i, 0, n - 1) +
                    min_area(grid, i + 1, j, 0, n - 1) +
                    min_area(grid, j + 1, m - 1, 0, n - 1));
        for (int i = 0; i < n; ++ i)
            for (int j = i + 1; j < n; ++ j)
                res = min(res, min_area(grid, 0, m - 1, 0, i) +
                    min_area(grid, 0, m - 1, i + 1, j) +
                    min_area(grid, 0, m - 1, j + 1, n - 1));
        return res;
    }
};
