int minDistance(char* word1, char* word2) {
    if (strcmp(word1, word2) == 0) {
        return 0;
    }
    const int l1 = strlen(word1);
    const int l2 = strlen(word2);
    int dp[l1 + 1][l2 + 1];
    for (int i = 0; i <= l1; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= l2; ++j)
        dp[0][j] = j;
    for (int i = 1; i <= l1; ++i)
        for (int j = 1; j <= l2; ++j)
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                char min = dp[i - 1][j - 1];
                if (dp[i - 1][j] < dp[i][j - 1]) {
                    if (min > dp[i - 1][j]) {
                        min = dp[i - 1][j];
                    }
                } else {
                    if (min > dp[i][j - 1]) {
                        min = dp[i][j - 1];
                    }
                }
                dp[i][j] = min + 1;
            }
    return dp[l1][l2];
}
