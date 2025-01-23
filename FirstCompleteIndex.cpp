class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> um;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                um[mat[i][j]] = {i, j};
        vector<int> r(m);
        vector<int> c(n);
        for (int k = 0;; ++ k) {
            auto [i, j] = um[arr[k]];
            ++ r[i];
            ++ c[j];
            if ((r[i] == n) || (c[j] == m))
                return k;
        }
        return 0;
    }
};
