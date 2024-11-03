class Solution {
public:
    void solve(int n, int i, vector<bool>&& c, vector<bool>&& d1,
           vector<bool>&& d2, vector<string>&& b,
           vector<vector<string>>& vs) {
        if (i == n) {
            vs.push_back(b);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (c[j] || d1[i + j] || d2[j - i + n - 1])
                continue;
            b[i][j] = 'Q';
            c[j] = true;
            d1[i + j] = true;
            d2[j - i + n - 1] = true;
            solve(n, i + 1, std::move(c), std::move(d1), std::move(d2),
                std::move(b), vs);
            c[j] = false;
            d1[i + j] = false;
            d2[j - i + n - 1] = false;
            b[i][j] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vs;
        solve(n, 0, vector<bool>(n), vector<bool>((n << 1) - 1), vector<bool>((n << 1) - 1),
        vector<string>(n, string(n, '.')), vs);
        return vs;        
    }
};
