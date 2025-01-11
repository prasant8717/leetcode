class Solution {
public:
    int find(vector<vector<int>>& v, int n, int i, int p, bool l) {
        if (i < 0)
            return 1;
        if ((l == 0) && (v[i][p] != -1))
            return v[i][p];
        int t = 1;
        if (l != 0)
            t = (n >> i) & 1;
        int res = 0;
        for (int j = 0; j <= t; ++ j) {
            if (j && p)
                continue;
            res += find(v, n, i - 1, j, (l != 0) && (j == t));
        }
        if (l == 0)
            v[i][p] = res;
        return res;
    }
    int findIntegers(int n) {
        int m = 32 - __builtin_clz(n);
        vector<vector<int>> vn(m, vector<int>(2, -1));
        return find(vn, n, m - 1, 0, true);
    }
};
