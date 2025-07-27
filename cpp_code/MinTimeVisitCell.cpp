class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if ((grid[0][1] > 1) && (grid[1][0] > 1))
            return -1;
        using tu = tuple<int, int, int>;
        priority_queue<tu, vector<tu>, greater<tu>> pq;
        pq.emplace(0, 0, 0);
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vv(m, vector<int>(n));
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                vv[i][j] = 1000000;
        vv[0][0] = 0;
        int d[5] = {-1, 0, 1, 0, -1};
        while (1) {
            auto [c, i, j] = pq.top();
            pq.pop();
            if ((i == (m - 1)) && (j == (n - 1)))
                return c;
            for (int k = 0; k < 4; ++ k) {
                int a = i + d[k];
                int b = j + d[k + 1];
                if ((a >= 0) && (a < m) &&
                    (b >= 0) && (b < n)) {
                    int t = c + 1;
                    if (t < grid[a][b])
                        t = grid[a][b] + (grid[a][b] - t) % 2;
                    if (t < vv[a][b]) {
                        vv[a][b] = t;
                        pq.emplace(t, a, b);
                    }
                }
            }
        }
    }
};
