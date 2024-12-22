class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        for (int i = 0; i < n; ++ i) {
            int mr = 0;
            int mc = 0;
            for (int j = 0; j < n; ++ j) {
                if (mr < grid[i][j])
                    mr = grid[i][j];
                if (mc < grid[j][i])
                    mc = grid[j][i];
                if (grid[i][j] != 0)
                    ++ res;
            }
            res += mr + mc;
        }
        return res;        
    }
};
