int minEatingSpeed(int* piles, int pilesSize, int h) {
    int max = 0;
    for (int i = 0; i < pilesSize; ++i)
    {
        if (max < piles[i])
        {
            max = piles[i];
        }
    }
    int l = 1;
    int r = max;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        int hhh = 0;
        for (int i = 0; i < pilesSize; ++i)
        {
            if (piles[i] % mid)
            {
                hhh += (piles[i] / mid) + 1;
            }
            else
            {
                hhh += (piles[i] / mid);
            }
        }
        if (hhh <= h)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return r;
}
