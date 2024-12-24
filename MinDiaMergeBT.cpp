class Solution {
public:
    void dfs(vector<vector<int>>& v, int i,
             int fa, int t, int& c, int& res) {
        for (int j = 0; j < v[i].size(); ++ j) {
            int tmp = v[i][j];
            if (tmp != fa) {
                dfs(v, tmp, i, t + 1, c, res);
            }
        }
        if (res < t) {
            res = t;
            c = i;
        }
    }
    int tdia(vector<vector<int>>& eds) {
        int n = eds.size();
        vector<vector<int>> v(n + 1);
        for (int i = 0; i < n; ++ i) {
            int e1 = eds[i][0];
            int e2 = eds[i][1];
            v[e1].push_back(e2);
            v[e2].push_back(e1);
        }
        int res = 0;
        int t = 0;
        dfs(v, 0, -1, 0, t, res);
        dfs(v, t, -1, 0, t, res);
        return res;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = tdia(edges1);
        int d2 = tdia(edges2);
        int res = d1;
        if (res < d2)
            res = d2;
        int t = ((d1 + 1) / 2) + ((d2 + 1) / 2) + 1;
        if (res < t)
            res = t;
        return res;
    }
};
