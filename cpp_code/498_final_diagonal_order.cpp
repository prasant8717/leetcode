class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int d = 1;
        int r = 0;
        int c = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> out(m * n);
        for (int i = 0; i < m * n; ++ i) {
            out[i] = mat[r][c];
            r -= d;
            c += d;
            if (r == m) {
                r = m - 1;
                c += 2;
                d = -d;
            }
            if (c == n) {
                c = n - 1;
                r += 2;
                d = -d;
            }
            if (r < 0) {
                r = 0;
                d = -d;
            }
            if (c < 0) {
                c = 0;
                d = -d;
            }
        }
        return out;
    }
};
