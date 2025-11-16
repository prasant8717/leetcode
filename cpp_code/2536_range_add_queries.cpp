class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n,
                                        vector<vector<int>>& queries) {
        vector<vector<int>> vv(n, vector<int>(n + 1));
        for (int i = 0; i < queries.size(); ++ i) {
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];
            for (int j = r1; j <= r2; ++ j) {
                ++ vv[j][c1];
                -- vv[j][c2 + 1];
            }
        }
        vector<vector<int>> out(n, vector<int>(n));
        for (int i = 0; i < n; ++ i) {
            int t = 0;
            for (int j = 0; j < n; ++ j) {
                t += vv[i][j];
                out[i][j] = t;
            }
        }
        return out;
    }
};
