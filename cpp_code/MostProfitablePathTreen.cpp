class Solution {
public:
    void net(vector<vector<int>>& g, vector<int>& ts,
             vector<int>& amt, int i, int fa, int t, int v, int& ans) {
        if (t == ts[i])
            v += amt[i] >> 1;
        else if (t < ts[i])
            v += amt[i];
        if (g[i].size() == 1 && g[i][0] == fa) {
            ans = max(ans, v);
            return;
        }
        for (int j = 0; j < g[i].size(); ++ j)
            if (g[i][j] != fa)
                net(g, ts, amt, g[i][j], i, t + 1, v, ans);
    }
    bool income(vector<vector<int>>& g, vector<int>& ts,
                int i, int fa, int t) {
        if (i == 0) {
            ts[i] = t;
            return true;
        }
        for (int j = 0; j < g[i].size(); ++ j) {
            if (g[i][j] != fa && income(g, ts, g[i][j], i, t + 1)) {
                ts[g[i][j]] = min(ts[g[i][j]], t + 1);
                return true;
            }
        }
        return false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int sz = edges.size() + 1;
        vector<vector<int>> vv(sz);
        for (int i = 0; i < edges.size(); ++ i) {
            int tr = edges[i][0];
            int tc = edges[i][1];
            vv[tr].emplace_back(tc);
            vv[tc].emplace_back(tr);
        }
        vector<int> vi(sz, sz);
        income(vv, vi, bob, -1, 0);
        vi[bob] = 0;
        int res = INT_MIN;
        net(vv, vi, amount, 0, -1, 0, 0, res);
        return res;
    }
};
