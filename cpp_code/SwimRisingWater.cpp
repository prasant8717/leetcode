class Solution {
public:
    int search(vector<int>& v, int val) {
        if (v[val] != val)
            v[val] = search(v, v[val]);
        return v[val];
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int nn = n * n;
        vector<int> v(nn);
        for (int i = 0; i < nn; ++ i)
            v[i] = i;
        vector<int> h(nn);
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j)
                h[grid[i][j]] = i * n + j;
        vector<int> d = {-1, 0, 1, 0, -1};
        for (int t = 0; t < nn; ++ t) {
            int i = h[t] / n;
            int j = h[t] % n;
            for (int k = 0; k < d.size() - 1; ++ k) {
                int x = i + d[k];
                int y = j + d[k + 1];
                if ((x >= 0) && (x < n) &&
                    (y >= 0) && (y < n) && (grid[x][y] <= t)) {
                    int tt = search(v, x * n + y);
                    v[tt] = search(v, h[t]);
                }
                int t0 = search(v, 0);
                int tn = search(v, nn - 1);
                if (t0 == tn)
                    return t;
            }
        }
        return -1;        
    }
};
