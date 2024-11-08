class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int d[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
            };
        vector<vector<int>> out(n, vector<int>(n));
        int i = 0;
        int j = 0;
        int k = 0;
        for (int t = 1; t <= n * n; ++ t) {
            out[i][j] = t;
            int r = i + d[k][0];
            int c = j + d[k][1];
            if ((r < 0) || (c < 0) ||
                (r >= n) || (c >= n) || out[r][c]) {
                k = (k + 1) % 4;
                r = i + d[k][0];
                c = j + d[k][1];
            }
            i = r;
            j = c;
        }
        return out;
    }
};
