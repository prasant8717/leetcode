class Solution {
public:
    int distance(vector<vector<int>>& v, int i, int n) {
        vector<bool> vb(n);
        vb[i] = true;
        queue<int> q{{i}};
        for (int j = 0;; ++ j) {
            for (int k = q.size(); k; -- k) {
                int t = q.front();
                q.pop();
                if (t == n - 1)
                    return j;
                for (int l = 0; l < v[t].size(); ++ l) {
                    int tt = v[t][l];
                    if (vb[tt] == false) {
                        vb[tt] = true;
                        q.push(tt);
                    }
                }
            }
        }
    };
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> v(n);
        for (int i = 0; i < n - 1; ++ i)
            v[i].push_back(i + 1);
        vector<int> out;
        for (int i = 0; i < queries.size(); ++ i) {
            v[queries[i][0]].push_back(queries[i][1]);
            out.push_back(distance(v, 0, n));
        }
        return out;
    }
};
