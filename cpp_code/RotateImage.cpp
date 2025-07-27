class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sz = matrix.size();
        for (int i = 0; i < (sz >> 1); ++ i) {
            for (int j = 0; j < sz; ++ j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[sz - i - 1][j];
                matrix[sz - i - 1][j] = tmp;
            }
        }
        for (int i = 0; i < sz; ++ i) {
            for (int j = 0; j < i; ++ j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }        
    }
};
