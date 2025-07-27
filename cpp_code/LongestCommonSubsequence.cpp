class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    const int l1 = text1.length();
    const int l2 = text2.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
    for (int i = 0; i < l1; ++i)
        for (int j = 0; j < l2; ++j)
            dp[i + 1][j + 1] = text1[i] == text2[j]
                               ? 1 + dp[i][j]
                               : max(dp[i][j + 1], dp[i + 1][j]);
        return dp[l1][l2];
    }
};
