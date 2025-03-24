class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> um;
        int n = arr.size();
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; ++ i) {
            um[arr[i]] = i;
            for (int j = 0; j < i; ++ j) {
                v[i][j] = 2;
            }
        }
        int res = 0;
        for (int i = 2; i < n; ++ i) {
            for (int j = 1; j < i; ++ j) {
                int t = arr[i] - arr[j];
                auto p = um.find(t);
                if ((p != um.end()) && (p->second < j)) {
                    int k = p->second;
                    if (v[i][j] < v[j][k] + 1)
                        v[i][j] = v[j][k] + 1;
                    if (res < v[i][j])
                        res = v[i][j];
                }
            }
        }
        return res;
    }
};
