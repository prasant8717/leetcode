class Solution {
public:
    int m;
    int n;
    int count_ways(vector<vector<int>>& vo,
                   vector<vector<int>>& vc,
                   string& ts, int i, int j) {
        if (i >= m)
            return 1;
        if (j >= n)
            return 0;
        if (vo[i][j] != -1)
            return vo[i][j];
        int res = count_ways(vo, vc, ts, i, j + 1);
        res = (res + 1LL * count_ways(vo, vc, ts, i + 1, j + 1) *
                vc[j][ts[i] - 'a']) % ((int)1e9 + 7);
        vo[i][j] = res;
        return res;
    }
    int numWays(vector<string>& words, string target) {
        m = target.size();
        n = words[0].size();
        vector<vector<int>> vc(n, vector<int>(26));
        for (int i = 0; i < words.size(); ++ i) {
            for (int j = 0; j < n; ++ j)
                ++ vc[j][words[i][j] - 'a'];
        }
        vector<vector<int>> vout(m, vector<int>(n, -1));
        return count_ways(vout, vc, target, 0, 0);
    }
};
