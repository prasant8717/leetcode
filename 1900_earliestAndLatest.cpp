vector<vector<vector<int>>> v(30, vector<vector<int>>(30, vector<int>(31)));
class Solution {
private:
    vector<int> play(int l, int r, int n) {
        if (v[l][r][n] != 0) {
            return {v[l][r][n] >> 8, v[l][r][n] & 0xFF};
        }
        if (l + r == n - 1) {
            v[l][r][n] = 0x101;
            return {1, 1};
        }
        int mn = INT_MAX;
        int mx = INT_MIN;
        int m = n >> 1;
        for (int i = 0; i < (1 << m); i ++) {
            vector<bool> vb(n, false);
            for (int j = 0; j < m; j ++) {
                if ((i >> j) & 1) {
                    vb[j] = true;
                } else {
                    vb[n - 1 - j] = true;
                }
            }
            if (n & 1) {
                vb[m] = true;
            }
            vb[n - 1 - l] = false;
            vb[n - 1 - r] = false;
            vb[l] = true;
            vb[r] = true;
            int a = 0, b = 0, c = 0;
            for (int j = 0; j < n; j++) {
                if (j == l) a = c;
                if (j == r) b = c;
                if (vb[j]) c++;
            }
            vector<int> t = play(a, b, c);
            if (mn > t[0] + 1)
                mn = t[0] + 1;
            if (mx < t[1] + 1)
                mx = t[1] + 1;
        }
        v[l][r][n] = (mn << 8) | mx;
        return {mn, mx};
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        return play(firstPlayer - 1, secondPlayer - 1, n);
    }
};
