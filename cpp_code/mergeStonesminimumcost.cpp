class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if (((n - 1) % (k - 1)) != 0)
            return -1;
        vector<int> vs(n + 1);
        for (int i = 1; i <= n; ++ i)
            vs[i] = vs[i - 1] + stones[i - 1];
        vector<vector<vector<int>>> vi(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, 0xFFFF)));
        for (int i = 1; i <= n; ++ i)
            vi[i][i][1] = 0;
        for (int j = 2; j <= n; ++ j) {
            for (int i = 1; i + j <= n + 1; ++ i) {
                int t = i + j - 1;
                for (int l = 1; l <= k; ++ l) {
                    for (int u = i; u < t; ++ u) {
                        int tt = vi[i][u][1] + vi[u + 1][t][l - 1];
                        if (vi[i][t][l] > tt)
                            vi[i][t][l] = tt;
                    }
                }
                vi[i][t][1] = vi[i][t][k] + vs[t] - vs[i - 1];
            }
        }
        return vi[1][n][1];
    }
};
