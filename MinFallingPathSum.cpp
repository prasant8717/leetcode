class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> vtmp(c);
        for (int i = 0; i < r; ++ i) {
            vector<int> t = vtmp;
            for (int j = 0; j < c; ++j) {
                if (j != 0) {
                    if (t[j] > vtmp[j - 1])
                        t[j] = vtmp[j - 1];
                }
                if (j + 1 < c) {
                    if (t[j] > vtmp[j + 1])
                        t[j] = vtmp[j + 1];
                }
                t[j] += matrix[i][j];
            }
            vtmp = move(t);
        }
        int res = INT_MAX;
        for (int i = 0; i < vtmp.size(); ++ i) {
            if (res > vtmp[i])
                res = vtmp[i];
        }
        return res;
    }
};
