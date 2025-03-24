class AndOp {
public:
    AndOp(int n) {
        vv = vector<int>(n);
        l = vector<int>(n, 1);
        iota(vv.begin(), vv.end(), 0);
    }

    bool combine(int u, int v) {
        int x = find(u);
        int y = find(v);
        if (x == y)
            return false;
        if (l[x] > l[y]) {
            vv[y] = x;
            l[x] += l[y];
        } else {
            vv[x] = y;
            l[y] += l[x];
        }
        return true;
    }

    int find(int n) {
        if (vv[n] != n)
            vv[n] = find(vv[n]);
        return vv[n];
    }

    int getSize(int n) {
        return l[find(n)];
    }

private:
    vector<int> vv;
    vector<int> l;
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vv = vector<int>(n, -1);
        ao = new AndOp(n);
        for (int i = 0; i < edges.size(); ++ i)
            ao->combine(edges[i][0], edges[i][1]);
        for (int i = 0; i < edges.size(); ++ i) {
            int root = ao->find(edges[i][0]);
            vv[root] &= edges[i][2];
        }
        vector<int> out;
        for (int i = 0; i < query.size(); ++ i)
            out.push_back(find(query[i][0], query[i][1]));
        return out;
    }

private:
    AndOp* ao;
    vector<int> vv;

    int find(int a, int b) {
        if (a == b)
            return 0;
        int u = ao->find(a);
        int v = ao->find(b);
        return u == v ? vv[u] : -1;
    }
};
