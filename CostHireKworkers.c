long long totalCost(int* costs, int costsSize, int k, int candidates) {
    int *low_cost = (int *)malloc(sizeof(int) * candidates);
    for (int i = 0; i < candidates; ++i)
    {
        for (int j = i + 1; j < costsSize; ++j)
        {
            if (costs[i] > costs[j])
            {
                int tmp = costs[j];
                costs[j] = costs[i];
                costs[i] = tmp;
            }
        }
        low_cost[i] = costs[i];
    }
    long long sum = 0;
    for (int i = 0; i < k; ++i)
    {
        sum += low_cost[i];
    }
    return sum;
}
