int numSquares(int n) {
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n + 1; ++ i)
        dp[i] = n;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++ i)
        for (int j = 1; j * j <= i; ++ j)
            if (dp[i] > dp[i - j * j] + 1)
                dp[i] = dp[i - j * j] + 1;
    return dp[n];
}
