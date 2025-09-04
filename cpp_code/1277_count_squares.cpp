class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++ i)
            for (int j = 0; j < matrix[0].size(); ++ j)
                if ((matrix[i][j] == 1) && (i > 0) && (j > 0)) {
                    int t = matrix[i - 1][j - 1];
                    if (t > matrix[i - 1][j])
                        t = matrix[i - 1][j];
                    if (t > matrix[i][j - 1])
                        t = matrix[i][j - 1];
                    matrix[i][j] += t;
                }
        return accumulate(matrix.begin(), matrix.end(), 0,
                      [](int t, vector<int>& v) {
            return t + accumulate(v.begin(), v.end(), 0);
        });
    }
};
