class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> vv(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                if (str1[i - 1] == str2[j - 1])
                    vv[i][j] = vv[i - 1][j - 1] + 1;
                else
                    if (vv[i - 1][j] > vv[i][j - 1])
                        vv[i][j] = vv[i - 1][j];
                    else
                        vv[i][j] = vv[i][j - 1];
            }
        }
        int i = m;
        int j = n;
        string res;
        while (i || j) {
            if (i == 0)
                res += str2[-- j];
            else if (j == 0)
                res += str1[-- i];
            else {
                if (vv[i][j] == vv[i][j - 1])
                    res += str2[-- j];
                else if (vv[i][j] == vv[i - 1][j])
                    res += str1[-- i];
                else {
                    res += str1[-- i];
                    -- j;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
