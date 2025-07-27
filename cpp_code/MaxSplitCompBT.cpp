class Solution {
public:
    long long splt(vector<vector<int>>& v,
                   vector<int>& vl,
                   int c,
                   int vi,
                   int& k,
                   int& rs) {
        long long s = vl[c];
        for (int j = 0; j < v[c].size(); ++ j)
            if (v[c][j] != vi)
                s += splt(v, vl, v[c][j], c, k, rs);
        if ((s % k) == 0)
            rs ++;
        return s;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int res = 0;
        vector<vector<int>> v(n);
        for (int i = 0; i < edges.size(); ++ i) {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        splt(v, values, 0, -1, k, res);
        return res;   
    }
};
