class BITree {
public:
    BITree(int n) {
        this->n = n;
        v.resize(n + 1, lim);
    }
    void modify(int a, int b) {
        while (a <= n) {
            if (v[a] > b)
                v[a] = b;
            a += a & -a;
        }
    }
    int search(int a) {
        int m = lim;
        while (a > 0) {
            if (m > v[a])
                m = v[a];
            a -= a & -a;
        }
        if (m == lim)
            return -1;
        return m;
    }
private:
    vector<int> v;
    int n;
    int lim = (1 << 30);
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int m = queries.size();
        int n = heights.size();
        for (int i = 0; i < m; ++ i) {
            int q0 = queries[i][0];
            int q1 = queries[i][1];
            if (q0 > q1) {
                queries[i][0] = q1;
                queries[i][1] = q0;
            }
        }
        vector<int> v(m);
        iota(v.begin(), v.end(), 0);
        ranges::sort(v, [&](int i, int j) {
            return queries[j][1] < queries[i][1];
        });
        vector<int> s = heights;
        ranges::sort(s);
        s.erase(unique(s.begin(), s.end()), s.end());
        vector<int> out(m);
        int j = n - 1;
        BITree bitt(n);
        for (int i = 0; i < v.size(); ++ i) {
            int t = v[i];
            int l = queries[t][0];
            int r = queries[t][1];
            while (j > r) {
                int k = s.end() - lower_bound(s.begin(), s.end(), heights[j]) + 1;
                bitt.modify(k, j);
                -- j;
            }
            if ((l == r) || (heights[l] < heights[r]))
                out[t] = r;
            else {
                int k = s.end() - lower_bound(s.begin(), s.end(), heights[l]);
                out[t] = bitt.search(k);
            }
        }
        return out;        
    }
};
