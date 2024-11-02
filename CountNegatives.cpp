class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++ i) {
            int l = 0;
            int r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (grid[i][mid] >= 0) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            res += (n - r);
        }
        return res;
    }
};
