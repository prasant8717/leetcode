int minCostClimbingStairs(int* cost, int costSize) {
    int dp1 = 0, dp2 = 0;
    for (int i = 0; i < costSize; i++)
    {
        int dp0 = cost[i];
        if (dp1 < dp2)
        {
            dp0 += dp1;
        }
        else
        {
            dp0 += dp2;
        }
        dp2 = dp1;
        dp1 = dp0;
    }
    if (dp1 < dp2)
    {
        return dp1;
    }
    else
    {
        return dp2;
    }
}
