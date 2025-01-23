class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> qp;
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> out(m, vector<int>(n));
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                out[i][j] = isWater[i][j] - 1;
                if (out[i][j] == 0) {
                    qp.emplace(i, j);
                }
            }
        }
        int ds[5] = {-1, 0, 1, 0, -1};
        while (qp.empty() == 0) {
            pair<int, int> tp = qp.front();
            qp.pop();
            for (int k = 0; k < 4; ++ k) {
                int tx = tp.first + ds[k];
                int ty = tp.second + ds[k + 1];
                if ((tx >= 0) && (tx < m) &&
                    (ty >= 0) && (ty < n) &&
                    (out[tx][ty] == -1)) {
                    out[tx][ty] = out[tp.first][tp.second] + 1;
                    qp.emplace(tx, ty);
                }
            }
        }
        return out;
    }
};
