class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> r(m);
        vector<int> c(n);
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (grid[i][j] != 0) {
                    ++ r[i];
                    ++ c[j];
                }
        int res = 0;
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if ((grid[i][j] != 0) &&
                    ((r[i] > 1) || (c[j] > 1)))
                    ++ res;
        return res;
    }
};
