class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int d[5] = {0, 1, 0, -1, 0};
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> res;
        bool ev[r][c];
        memset(ev, false, sizeof(ev));
        for (int l = r * c; l; -- l) {
            res.push_back(matrix[i][j]);
            ev[i][j] = true;
            int rr = i + d[k];
            int cc = j + d[k + 1];
            if ((rr < 0) || (rr >= r) ||
                (cc < 0) || (cc >= c) || ev[rr][cc]) {
                k = (k + 1) % 4;
            }
            i += d[k];
            j += d[k + 1];
        }
        return res;        
    }
};
