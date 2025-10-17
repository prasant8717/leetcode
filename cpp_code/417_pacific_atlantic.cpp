class Solution {
private:
    void check(vector<vector<int>>& vh, int i, int j,
           vector<vector<bool>>& vb, int h = 0) {
        if ((i < 0) || (i == vh.size()) ||
            (j < 0) || (j == vh[0].size()))
            return;
        if ((vb[i][j] != 0) || (vh[i][j] < h))
            return;
        vb[i][j] = true;
        check(vh, i + 1, j, vb, vh[i][j]);
        check(vh, i - 1, j, vb, vh[i][j]);
        check(vh, i, j + 1, vb, vh[i][j]);
        check(vh, i, j - 1, vb, vh[i][j]);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> v1(m, vector<bool>(n));
        vector<vector<bool>> v2(m, vector<bool>(n));
        vector<vector<int>> out;
        for (int i = 0; i < m; ++ i) {
            check(heights, i, 0, v1);
            check(heights, i, n - 1, v2);
        }
        for (int j = 0; j < n; ++ j) {
            check(heights, 0, j, v1);
            check(heights, m - 1, j, v2);
        }
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (v1[i][j] && v2[i][j])
                    out.push_back({i, j});
        return out;
    }
};
