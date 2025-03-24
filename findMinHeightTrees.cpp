class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        vector<int> vd(n);
        vector<vector<int>> vv(n);
        for (int i = 0; i < edges.size(); ++ i) {
            int t1 = edges[i][0];
            int t2 = edges[i][1];
            vv[t1].push_back(t2);
            vv[t2].push_back(t1);
            ++ vd[t1];
            ++ vd[t2];
        }
        queue<int> q;
        for (int i = 0; i < n; ++ i)
            if (vd[i] == 1)
                q.push(i);
        vector<int> out;
        while (q.empty() == 0) {
            out.clear();
            for (int i = q.size(); i > 0; -- i) {
                int t = q.front();
                q.pop();
                out.push_back(t);
                for (int j = 0; j < vv[t].size(); ++ j)
                    if (-- vd[vv[t][j]] == 1)
                        q.push(vv[t][j]);
            }
        }
        return out;
    }
};
