class Solution {
private:
    struct Grid {
        vector<int> par;
        vector<priority_queue<int, vector<int>, greater<int>>> pq;
        vector<bool> active;

        Grid(int n) {
            par.resize(n);
            pq.resize(n);
            active.resize(n, true);
            for (int i = 0; i < n; ++i) {
                par[i] = i;
                pq[i].push(i);
            }
        }

        int find(int u) {
            if (par[u] == u) return u;
            return par[u] = find(par[u]);
        }

        void unite(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) return;
            if (pq[pu].size() > pq[pv].size()) {
                while (!pq[pv].empty()) {
                    pq[pu].push(pq[pv].top());
                    pq[pv].pop();
                }
                par[pv] = pu;
            } else {
                while (!pq[pu].empty()) {
                    pq[pv].push(pq[pu].top());
                    pq[pu].pop();
                }
                par[pu] = pv;
            }
        }

        void deactivate(int u) {
            active[u] = false;
        }

        int check(int u) {
            if (active[u]) return u;
            int pu = find(u);
            while (!pq[pu].empty() && !active[pq[pu].top()])
                pq[pu].pop();
            return !pq[pu].empty() ? pq[pu].top() : -2;
        }
    };

public:
    vector<int> processQueries(int c, const vector<vector<int>>& connections, const vector<vector<int>>& queries) {
        Grid grid(c);
        for (auto& con : connections) {
            int u = con[0];
            int v = con[1];
            grid.unite(u - 1, v - 1);
        }
        vector<int> res;
        for (auto& q : queries)
            if (q[0] == 1)
                res.push_back(grid.check(q[1] - 1) + 1);
            else
                grid.deactivate(q[1] - 1);
        return res;
    }
};

