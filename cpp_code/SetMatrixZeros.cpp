class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        bool rsts = false;
        for (int j = 0; j < c; ++ j)
            if (matrix[0][j] == 0) {
                rsts = true;
                break;
            }
        bool csts = false;
        for (int i = 0; i < r; ++ i)
            if (matrix[i][0] == 0) {
                csts = true;
                break;
            }
        for (int i = 1; i < r; ++ i)
            for (int j = 1; j < c; ++ j)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for (int i = 1; i < r; ++ i)
            for (int j = 1; j < c; ++ j)
                if ((matrix[i][0] == 0) || (matrix[0][j] == 0))
                    matrix[i][j] = 0;
        if (rsts)
            for (int j = 0; j < c; ++ j)
                matrix[0][j] = 0;
        if (csts)
            for (int i = 0; i < r; ++i)
                matrix[i][0] = 0;
    }
};
