class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l = s.size();
        vector<vector<int>> v(l, vector<int>(l));
        for (int i = 0; i < l; ++ i) {
            v[i][i] = 1;
        }
        for (int i = l - 1; ~i; -- i) {
            for (int j = i + 1; j < l; ++ j) {
                if (s[i] == s[j]) {
                    v[i][j] = v[i + 1][j - 1] + 2;
                } else {
                    v[i][j] = v[i + 1][j];
                    if (v[i][j] < v[i][j - 1])
                        v[i][j] = v[i][j - 1];
                }
            }
        }
        return v[0][l - 1];        
    }
};
