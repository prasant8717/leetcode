class Solution {
private:
    int top_left(vector<vector<int>>& vf) {
        int res = 0;
        int n = vf.size();
        for (int i = 0; i < n; ++ i)
            res += vf[i][i];
        return res;
    }

    int top_right(vector<vector<int>>& vf) {
        int n = vf.size();
        vector<vector<int>> vp(n, vector<int>(n));
        vp[0][n - 1] = vf[0][n - 1];
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if ((i >= j) && (!((i == n - 1) && (j == n - 1))))
                    continue;
                for (auto& [di, dj] : vector<pair<int, int>>{{1, -1}, {1, 0}, {1, 1}}) {
                    int ii = i - di;
                    int jj = j - dj;
                    if ((ii < 0) || (ii == n) || (jj < 0) || (jj == n))
                        continue;
                    if ((ii < jj) && (jj < n - 1 - ii))
                        continue;
                    int t = vp[ii][jj] + vf[i][j];
                    if (vp[i][j] < t)
                        vp[i][j] = t;
                }
            }
        }
        return vp[n - 1][n - 1];
    }

    int bot_left(vector<vector<int>>& vf) {
        int n = vf.size();
        vector<vector<int>> vp(n, vector<int>(n));
        vp[n - 1][0] = vf[n - 1][0];
        for (int j = 0; j < n; ++ j) {
            for (int i = 0; i < n; ++ i) {
                if ((i <= j) && (!((i == n - 1) && (j == n - 1))))
                    continue;
                for (auto& [di, dj] : vector<pair<int, int>>{{-1, 1}, {0, 1}, {1, 1}}) {
                    int ii = i - di;
                    int jj = j - dj;
                    if ((ii < 0) || (ii == n) || (jj < 0) || (jj == n))
                        continue;
                    if ((jj < ii) && (ii < n - 1 - jj))
                        continue;
                    int t = vp[ii][jj] + vf[i][j];
                    if (vp[i][j] < t)
                        vp[i][j] = t;
                }
            }
        }
        return vp[n - 1][n - 1];
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        return top_left(fruits) + top_right(fruits) +
            bot_left(fruits) - 2 * fruits.back().back();
    }
};
