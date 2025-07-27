class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        vector<vector<long>> vout(r + 1, vector<long>(c + 1, 0));
        vout[0][1] = 1;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    vout[i + 1][j + 1] = vout[i][j + 1] + vout[i + 1][j];
                }
            }
        }
        return vout[r][c];
    }
};
