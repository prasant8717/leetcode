class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        vector<vector<int>> v(l1 + 1, vector<int>(l2 + 1));
        for (int i = 1; i <= l1; ++ i) {
            v[i][0] = v[i - 1][0] + s1[i - 1];
        }
        for (int j = 1; j <= l2; ++ j) {
            v[0][j] = v[0][j - 1] + s2[j - 1];
        }
        for (int i = 1; i <= l1; ++ i) {
            for (int j = 1; j <= l2; ++ j) {
                if (s1[i - 1] == s2[j - 1]) {
                    v[i][j] = v[i - 1][j - 1];
                } else {
                    v[i][j] = v[i - 1][j] + s1[i - 1];
                    if (v[i][j] > v[i][j - 1] + s2[j - 1])
                        v[i][j] = v[i][j - 1] + s2[j - 1];
                }
            }
        }
        return v[l1][l2];        
    }
};
