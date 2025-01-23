class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long sum1 = 0;
        long long sum2 = 0;
        long long res = LONG_MAX;
        int n = grid[0].size();
        for (int i = 0; i < n; ++ i)
            sum1 += grid[0][i];
        for (int j = 0; j < n; ++ j) {
            sum1 -= grid[0][j];
            long long m = sum1 > sum2 ? sum1 : sum2;
            if (res > m)
                res = m;
            sum2 += grid[1][j];
        }
        return res;        
    }
};
