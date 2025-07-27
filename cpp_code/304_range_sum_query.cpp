class NumMatrix {
private:
    vector<vector<int>> vv;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vv.resize(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                vv[i + 1][j + 1] = vv[i + 1][j] + vv[i][j + 1] -
                    vv[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return vv[row2 + 1][col2 + 1] - vv[row2 + 1][col1] -
            vv[row1][col2 + 1] + vv[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
