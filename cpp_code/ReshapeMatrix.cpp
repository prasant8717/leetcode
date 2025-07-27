class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        int mn = n * m;
        int rc = r * c;
        if (mn != rc)
            return mat;
        vector<vector<int>> out(r, vector<int>(c));
        for (int i = 0; i < rc; i ++)
            out[i / c][i % c] = mat[i / m][i % m];
        return out;        
    }
};
