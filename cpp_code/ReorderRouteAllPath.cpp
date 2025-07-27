class Solution {
public:
    int dfs(const vector<vector<int>>& gr, int sel, int p) {
        int chg = 0;
        for (const int val : gr[sel]) {
            if (abs(val) == p)
                continue;
            if (val > 0)
                ++chg;
            chg += dfs(gr, abs(val), sel);
        }
        return chg;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> gr(n);
        for (const vector<int>& con : connections) {
            const int u = con[0];
            const int v = con[1];
            gr[u].push_back(v);
            gr[v].push_back(-u);
        }
        return dfs(gr, 0, -1);      
    }
};
