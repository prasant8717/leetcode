class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        queue<int> q;
        int n = graph.size();
        vector<int> id(n);
        vector<vector<int>> v(n);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < graph[i].size(); ++ j)
                v[graph[i][j]].push_back(i);
            id[i] = graph[i].size();
            if (id[i] == 0)
                q.push(i);
        }
        while (q.empty() == 0) {
            int i = q.front();
            q.pop();
            for (int j = 0; j < v[i].size(); ++ j)
                if (-- id[v[i][j]] == 0)
                    q.push(v[i][j]);
        }
        vector<int> res;
        for (int i = 0; i < n; ++ i)
            if (id[i] == 0)
                res.push_back(i);
        return res;
    }
};
