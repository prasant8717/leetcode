class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> v(m + 1, vector<int>(n + 1));
        for (int i = 0; i < strs.size(); ++ i) {
            int zs = ranges::count(strs[i], '0');
            int os = strs[i].length() - zs;
            for (int i = m; i >= zs; -- i)
                for (int j = n; j >= os; -- j) {
                    int t = v[i - zs][j - os] + 1;
                    if (v[i][j] < t)
                        v[i][j] = t;
                }
        }
        return v[m][n];
    }
};
