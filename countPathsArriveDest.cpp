class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long lx = LLONG_MAX >> 1;
        int m = 1e9 + 7;
        vector<vector<long long>> vl(n, vector<long long>(n, lx));
        for (int i = 0; i < vl.size(); ++ i)
            fill(vl[i].begin(), vl[i].end(), lx);
        for (int i = 0; i < roads.size(); ++ i) {
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];
            vl[u][v] = t;
            vl[v][u] = t;
        }
        vl[0][0] = 0;
        vector<long long> v(n, lx);
        v[0] = 0;
        vector<long long> vv(n);
        vv[0] = 1;
        vector<bool> vb(n);
        for (int i = 0; i < n; ++ i) {
            int t = -1;
            for (int j = 0; j < n; ++ j)
                if ((vb[j] == false) && ((t == -1) || (v[j] < v[t])))
                    t = j;
            vb[t] = true;
            for (int j = 0; j < n; ++ j) {
                if (j == t)
                    continue;
                long long k = v[t] + vl[t][j];
                if (v[j] > k) {
                    v[j] = k;
                    vv[j] = vv[t];
                } else if (v[j] == k)
                    vv[j] = (vv[j] + vv[t]) % m;
            }
        }
        return (int) vv[n - 1];
    }
};
