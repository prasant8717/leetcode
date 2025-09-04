class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> out(n, vector<int>(n));
        vector<vector<int>> vdg(2 * n + 1);
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j)
                vdg[i - j + n].push_back(grid[i][j]);
        for (int i = 0; i < 2 * n + 1; ++i)
            if (i < n)
                ranges::sort(vdg[i], greater<int>());
            else
                ranges::sort(vdg[i]);
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j) {
                out[i][j] = vdg[i - j + n].back();
                vdg[i - j + n].pop_back();
            }
        return out;
    }
};
