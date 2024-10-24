class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pcnt(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                pcnt[j] += pcnt[j - 1];
            }
        }
        return pcnt[n - 1];
    }
};
