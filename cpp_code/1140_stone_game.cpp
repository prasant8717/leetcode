class Solution {
private:
    int stoneGameII(vector<int>& v, vector<vector<int>>& vv,
                    int i, int j) {
        if (i + (j << 1) >= vv.size())
            return v[i];
        if (vv[i][j] > 0)
            return vv[i][j];
        int t = v[i];
        for (int k = 1; k <= (j << 1); ++ k)
            t = min(t, stoneGameII(v, vv, i + k, max(j, k)));
        return vv[i][j] = v[i] - t;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> vv(n, vector<int>(n));
        vector<int> v = piles;
        for (int i = n - 2; i >= 0; --i)
            v[i] += v[i + 1];
        return stoneGameII(v, vv, 0, 1);
    }
};
