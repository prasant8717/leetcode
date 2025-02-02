class Solution {
public:
    int find(vector<int>& v, int t) {
        if (v[t] != t) {
            v[t] = find(v, v[t]);
        }
        return v[t];
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> vp(n * n);
        vector<int> vs(n * n, 1);
        iota(vp.begin(), vp.end(), 0);
        int res = 1;
        vector<int> ds = {-1, 0, 1, 0, -1};
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] != 0) {
                    for (int k = 0; k < 4; ++ k) {
                        int tx = i + ds[k];
                        int ty = j + ds[k + 1];
                        if ((tx >= 0) && (tx < n) &&
                            (ty >= 0) && (ty < n) &&
                            (grid[tx][ty] != 0)) {
                            int t1 = find(vp, tx * n + ty);
                            int t2 = find(vp, i * n + j);
                            if (t1 == t2)
                                continue;
                            vp[t1] = t2;
                            vs[t2] += vs[t1];
                            if (res < vs[t2])
                                res = vs[t2];
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 0) {
                    int t = 1;
                    unordered_set<int> us;
                    for (int k = 0; k < 4; ++ k) {
                        int tx = i + ds[k];
                        int ty = j + ds[k + 1];
                        if ((tx >= 0) && (tx < n) &&
                            (ty >= 0) && (ty < n) &&
                            (grid[tx][ty] != 0)) {
                            int r = find(vp, tx * n + ty);
                            if (us.count(r) == 0) {
                                us.insert(r);
                                t += vs[r];
                            }
                        }
                    }
                    if (res < t)
                        res = t;
                }
            }
        }
        return res;
    }
};
