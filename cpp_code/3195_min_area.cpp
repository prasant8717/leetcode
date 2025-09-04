class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int a1 = INT_MAX;
        int b1 = INT_MAX;
        int a2 = 0;
        int b2 = 0;
        for (int i = 0; i < grid.size(); ++ i)
            for (int j = 0; j < grid[0].size(); ++ j)
                if (grid[i][j] == 1) {
                    if (a1 > i)
                        a1 = i;
                    if (b1 > j)
                        b1 = j;
                    if (a2 < i)
                        a2 = i;
                    if (b2 < j)
                        b2 = j;
                }
        return (a2 - a1 + 1) * (b2 - b1 + 1);
    }
};
