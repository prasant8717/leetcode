class Solution {
private:
    pair<int, int> dfs(vector<vector<int>>& vv,
                       vector<bool> &vb, int i) {
        vb[i] = true;
        int r = 1;
        int c = vv[i].size();
        for (int j = 0; j < vv[i].size(); ++ j) {
            int t = vv[i][j];
            if (vb[t] == false) {
                auto [x, y] = dfs(vv, vb, t);
                r += x;
                c += y;
            }
        }
        return make_pair(r, c);
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vb(n);
        vector<vector<int>> vv(n);
        for (int i = 0; i < edges.size(); ++ i) {
            int t1 = edges[i][0];
            int t2 = edges[i][1];
            vv[t1].push_back(t2);
            vv[t2].push_back(t1);
        }
        int res = 0;
        for (int i = 0; i < n; ++ i) {
            if (vb[i] == false) {
                auto [x, y] = dfs(vv, vb, i);
                if (x * (x - 1) == y)
                    ++ res;
            }
        }
        return res;
    }
};
