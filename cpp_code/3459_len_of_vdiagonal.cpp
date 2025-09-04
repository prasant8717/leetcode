class Solution {
private:
    static constexpr int da[4][2] = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    int diag(vector<vector<int>>& vi, int i, int j, bool sts, int n,
        int d, vector<int>& vvm) {
        if ((i < 0) || (i == vi.size()) ||
            (j < 0) || (j == vi[0].size()))
            return 0;
        if (vi[i][j] != n)
            return 0;
        int h = 0;
        if (h < n - 1)
            h = n - 1;
        int idx = (((i * vi[0].size() + j) * 2 + sts) * 2 + h) * 4 + d;
        if (vvm[idx] != -1)
            return vvm[idx];
        int nm = 2;
        if (n == 2)
            nm = 0;
        auto& [d1, d2] = da[d];
        int res = 1 + diag(vi, i + d1, j + d2, sts, nm, d, vvm);
        if (!sts) {
            int nd = (d + 1) % 4;
            auto& [ndx, ndy] = da[nd];
            int t = 1 + diag(vi, i + ndx, j + ndy, true, nm, nd, vvm);
            if (res < t)
                res = t;
        }
        vvm[idx] = res;
        return res;
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sz = m * n * 2 * 2 * 4;
        vector<int> vvm(sz, -1);
        int res = 0;
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (grid[i][j] == 1)
                    for (int k = 0; k < 4; ++ k) {
                        auto& [d1, d2] = da[k];
                        int t = 1 + diag(grid, i + d1, j + d2,
                                        false, 2, k, vvm);
                        if (res < t)
                            res = t;
                    }
        return res;
    }
};
