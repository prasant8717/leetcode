class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        if (l1 + l2 != s3.length()) {
            return false;
        }
        vector<vector<bool>> vout(l1 + 1, vector<bool>(l2 + 1));
        vout[0][0] = true;
        for (int i = 0; i < l1; ++i) {
            vout[i + 1][0] = vout[i][0] && (s1[i] == s3[i]);
        }
        for (int j = 0; j < l2; ++j) {
            vout[0][j + 1] = vout[0][j] && (s2[j] == s3[j]);
        }
        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j) {
                vout[i + 1][j + 1] = (vout[i][j + 1] && (s1[i] == s3[i + j + 1])) || (vout[i + 1][j] && (s2[j] == s3[i + j + 1]));
            }
        }
        return vout[l1][l2];
    }
};
