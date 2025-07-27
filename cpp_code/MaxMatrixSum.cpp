class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int c = 0;
        int min = INT_MAX;
        for (int i = 0; i < matrix.size(); ++ i) {
            for (int j = 0; j < matrix[0].size(); ++ j) {
                int t = matrix[i][j];
                if (t < 0) {
                    t = t * -1;
                    c ++;
                }
                res = res + t;
                if (min > t)
                    min = t;
            }
        }
        if (((c % 2) == 0) || (min == 0))
            return res;
        return res - (min * 2);
    }
};
