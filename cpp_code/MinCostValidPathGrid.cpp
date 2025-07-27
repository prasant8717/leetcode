class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ds = {{0, 0},
                                 {0, 1},
                                 {0, -1},
                                 {1, 0},
                                 {-1, 0}};
        vector<vector<bool>> v(m, vector<bool>(n));
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        while (dq.empty() == 0) {
            auto td = dq.front();
            dq.pop_front();
            int i = td.first / n;
            int j = td.first % n;
            int k = td.second;
            if ((i == m - 1) && (j == n - 1))
                return k;
            if (v[i][j])
                continue;
            v[i][j] = true;
            for (int t = 1; t <= 4; ++ t) {
                int tx = i + ds[t][0];
                int ty = j + ds[t][1];
                if ((tx >= 0) && (tx < m) &&
                    (ty >= 0) && (ty < n)) {
                    if (grid[i][j] == t)
                        dq.push_front({tx * n + ty, k});
                    else
                        dq.push_back({tx * n + ty, k + 1});
                }
            }
        }
        return -1;
    }
};
