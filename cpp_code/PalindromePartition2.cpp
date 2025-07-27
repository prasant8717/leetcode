class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> vb(n, vector<bool>(n, true));
        for (int i = 2; i <= n; ++ i) {
            int k = 0;
            for (int j = i - 1; j < n; ++ j) {
                vb[k][j] = (s[k] == s[j]) && vb[k + 1][j - 1];
                ++ k;
            }
        }
        vector<int> vp(n, n);
        for (int i = 0; i < n; ++ i) {
            if (vb[0][i] == true) {
                vp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; ++ j)
                if (vb[j + 1][i] == true)
                    if (vp[i] > vp[j] + 1)
                        vp[i] = vp[j] + 1;
        }
        return vp[n - 1];        
    }
};
