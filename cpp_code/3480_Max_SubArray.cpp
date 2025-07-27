class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> vvc(n + 1);
        for (auto vt : conflictingPairs) {
            int a = vt[0];
            int b = vt[1];
            int mn = a < b ? a : b;
            int mx = a < b ? b : a;
            vvc[mx].push_back(mn);
        }
        int ml = 0;
        int sml = 0;
        long long lv = 0;
        vector<long long> vl(n + 1);
        for (int i = 1; i <= n; ++ i) {
            for (int j : vvc[i]) {
                if (j > ml) {
                    sml = ml;
                    ml = j;
                } else if (j > sml) {
                    sml = j;
                }
            }
            lv += i - ml;
            vl[ml] += ml - sml;
        }
        return lv + ranges::max(vl);
    }
};
