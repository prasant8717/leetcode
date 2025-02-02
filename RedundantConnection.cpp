class Solution {
public:
    int find(vector<int>& v, int n) {
        int t = n;
        if (n != v[n]) {
            v[n] = find(v, v[n]);
            t = v[n];
        }
        return t;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> v(n);
        iota(v.begin(), v.end(), 0);
        for (int i = 0; ; ++ i) {
            int ta = find(v, edges[i][0] - 1);
            int tb = find(v, edges[i][1] - 1);
            if (ta == tb) {
                return edges[i];
            }
            v[ta] = tb;
        }
    }
};
