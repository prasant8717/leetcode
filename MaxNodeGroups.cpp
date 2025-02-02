class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> vv(n, vector<int>());
        for (int i = 0; i < edges.size(); ++ i) {
            int t1 = edges[i][0] - 1;
            int t2 = edges[i][1] - 1;
            vv[t1].push_back(t2);
            vv[t2].push_back(t1);
        }
        vector<int> vo(n);
        for (int i = 0; i < n; ++ i) {
            queue<int> q{{i}};
            vector<int> vs(n);
            vs[i] = 1;
            int m = 1;
            int r = i;
            while (q.size() != 0) {
                int t = q.front();
                q.pop();
                if (r > t)
                    r = t;
                for (int j = 0; j < vv[t].size(); ++ j) {
                    int k = vv[t][j];
                    if (vs[k] == 0) {
                        vs[k] = vs[t] + 1;
                        if (m < vs[k])
                            m = vs[k];
                        q.push(k);
                    } else if (abs(vs[k] - vs[t]) != 1) {
                        return -1;
                    }
                }
            }
            if (vo[r] < m)
                vo[r] = m;
        }
        int res = 0;
        for (int i = 0; i < vo.size(); ++ i)
            res += vo[i];
        return res;
    }
};
