class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> vtmp(r, vector<int>(c));
        int max = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if ((i == 0) || (j == 0) || (matrix[i][j] == '0')) {
                    vtmp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                } else {
                    int min = vtmp[i - 1][j - 1];
                    if (min > vtmp[i - 1][j]) {
                        min = vtmp[i - 1][j];
                    }
                    if (min > vtmp[i][j - 1]) {
                        min = vtmp[i][j - 1];
                    }
                    vtmp[i][j] = min + 1;
                }
                if (vtmp[i][j] > max) {
                    max = vtmp[i][j];
                }
            }
        }
        return max * max;        
    }
};
