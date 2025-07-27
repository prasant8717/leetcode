class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> l(c, 0);
        vector<int> rr(c, c);
        vector<int> h(c, 0);
        int m = 0;
        for (int i = 0; i < r; ++ i) {
            int cl = 0, cr = c;
            for (int j = 0; j < c; ++ j) {
                if (matrix[i][j] == '1') {
                    h[j] ++;
                } else {
                    h[j] = 0;
                }
            }
            for (int j = 0; j < c; ++ j) {
                if (matrix[i][j] == '1') {
                    l[j] = max(l[j], cl);
                } else {
                    l[j] = 0;
                    cl = j + 1;
                }
            }
            for (int j = c - 1; j >= 0; -- j) {
                if (matrix[i][j] == '1') {
                    rr[j] = min(rr[j], cr);
                } else {
                    rr[j] = c;
                    cr = j;
                }
            }
            for (int j = 0; j < c; j++) {
                m = max(m, (rr[j] - l[j]) * h[j]);
            }
        }
        return m;
    }
};
