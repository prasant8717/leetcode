class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++ i)
            for (int j = 0; j < grid.size(); ++ j) {
                if (grid[i][j])
                    res += (grid[i][j] << 2) + 2;
                if (i > 0)
                    if (grid[i][j] > grid[i - 1][j])
                        res -= (grid[i - 1][j] << 1);
                    else
                        res -= (grid[i][j] << 1);
                if (j > 0)
                    if (grid[i][j] > grid[i][j - 1])
                        res -= (grid[i][j - 1] << 1);
                    else
                        res -= (grid[i][j] << 1);
            }
        return res;
    }
};
