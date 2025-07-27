class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        using tiii = tuple<int, int, int>;
        priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> vb(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if ((i == 0) || (i == m - 1) ||
                    (j == 0) || (j == n - 1)) {
                    pq.emplace(heightMap[i][j], i, j);
                    vb[i][j] = true;
                }
            }
        }
        int res = 0;
        int ds[5] = {-1, 0, 1, 0, -1};
        while (pq.empty() == 0) {
            auto [h, i, j] = pq.top();
            pq.pop();
            for (int k = 0; k < 4; ++ k) {
                int tx = i + ds[k];
                int ty = j + ds[k + 1];
                if ((tx >= 0) && (tx < m) && 
                    (ty >= 0) && (ty < n) &&
                    (vb[tx][ty] == false)) {
                    int t = h - heightMap[tx][ty];
                    if (t > 0)
                        res += t;
                    vb[tx][ty] = true;
                    int tt = h;
                    if (tt < heightMap[tx][ty])
                        tt = heightMap[tx][ty];
                    pq.emplace(tt, tx, ty);
                }
            }
        }
        return res;
    }
};
