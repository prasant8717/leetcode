class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int l = values.size();
        vector<vector<int>> vv(l, vector<int>(l));
        for (int j = 2; j < l; ++ j)
            for (int i = j - 2; i >= 0; -- i) {
                vv[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++ k) {
                    int t = vv[i][k] + vv[k][j] +
                            values[i] * values[k] * values[j];
                    if (t < vv[i][j])
                        vv[i][j] = t;
                }
            }
        return vv[0][l - 1];
    }
};
