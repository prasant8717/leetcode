class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> v(m, vector<bool>(n));
        deque<tuple<int, int, int>> dq{{0, 0, 0}};
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (1) {
            auto [i, j, k] = dq.front();
            dq.pop_front();
            if ((i == (m - 1)) && (j == (n - 1)))
                return k;
            if (v[i][j] == true)
                continue;
            v[i][j] = true;
            for (int d = 0; d < 4; ++ d) {
                int a = i + dirs[d];
                int b = j + dirs[d + 1];
                if ((a >= 0) && (a < m) &&
                    (b >= 0) && (b < n)) {
                    if (grid[a][b] == 0)
                        dq.push_front({a, b, k});
                    else
                        dq.push_back({a, b, k + 1});
                }
            }
        }        
    }
};
