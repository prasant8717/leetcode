class Solution {
public:
    void generate(int n, int sz, vector<vector<int>>& v) {
        if (n == 1)
            v.push_back({1});
        if (n == sz)
            return;
        vector<int> t;
        for (int i = 0; i < n + 1; ++ i) {
            if (i == 0)
                t.push_back(v[n - 1][0]);
            else if (i == n)
                t.push_back(v[n - 1][n - 1]);
            else
                t.push_back(v[n - 1][i - 1] + v[n - 1][i]);
        }
        v.push_back(t);
        generate(n + 1, sz, v);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out;
        generate(1, numRows, out);
        return out;
    }
};
