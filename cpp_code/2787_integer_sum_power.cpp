class Solution {
public:
    int numberOfWays(int n, int x) {
        int m = 1e9 + 7;
        vector<vector<int>> v(n + 1, vector<int>(n + 1));
        v[0][0] = 1;
        for (int i = 1; i <= n; ++ i) {
            long long t = (long long) pow(i, x);
            for (int j = 0; j <= n; ++ j) {
                v[i][j] = v[i - 1][j];
                if (t <= j) {
                    v[i][j] = (v[i][j] + v[i - 1][j - t]) % m;
                }
            }
        }
        return v[n][n];
    }
};
