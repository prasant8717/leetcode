class Solution {
private:
    static constexpr int mod = 1e9 + 7;

    long long chkpow(long long l, long long n) {
        if (n == 0)
            return 1;
        if ((n % 2) == 1)
            return l * chkpow(l % mod, (n - 1)) % mod;
        return chkpow(l * l % mod, (n / 2)) % mod;
    }

    vector<vector<int>> form(int n, int k) {
        vector<vector<int>> vv(n + 1, vector<int>(k + 1));
        for (int i = 0; i <= n; ++i)
            vv[i][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= k; ++j)
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
        return vv;
    }

    int check(vector<vector<vector<vector<int>>>>& vvvv,
              vector<vector<int>>& vv, vector<int>& v,
              int m, int k, int i, unsigned int c) {
        if ((m < 0) || (k < 0) || (m + popcount(c) < k))
            return 0;
        if (m == 0)
            return k == popcount(c) ? 1 : 0;
        if (i == v.size())
            return 0;
        if (vvvv[m][k][i][c] != -1)
            return vvvv[m][k][i][c];
        int res = 0;
        for (int j = 0; j <= m; ++ j) {
            long long ll = vv[m][j] * chkpow(v[i], j) % mod;
            int t = c + j;
            res = (res + static_cast<long long>(check(vvvv, vv, v,
                   m - j, k - (t % 2), i + 1, t / 2)) * ll) % mod;
        }
        return vvvv[m][k][i][c] = res;
    }

public:
    int magicalSum(int m, int k, vector<int>& v) {
        vector<vector<vector<vector<int>>>> vvvv(m + 1,
                vector<vector<vector<int>>>(k + 1,
                vector<vector<int>>(v.size() + 1,
                vector<int>(m + 1, -1))));
        vector<vector<int>> vv = form(m, m);
        return check(vvvv, vv, v, m, k, 0, 0);
    }
};
