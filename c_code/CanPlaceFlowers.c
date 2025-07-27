bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    bool sts = false;
    int req = 0;
    if (flowerbedSize != 0)
    {
        for (int i = 0; i < flowerbedSize; i ++)
        {
            if (flowerbed[i] == 0)
            {
                bool prev = (i == 0) || (flowerbed[i - 1] == 0);
                bool next = (i == flowerbedSize - 1) || (flowerbed[i + 1] == 0);
                if (prev && next)
                {
                    req ++;
                    flowerbed[i] = 1;
                    if (req >= n)
                        return true;
                }
            }
        }
        if (req >= n)
        {
            sts = true;
        }
    }
    return sts;
}
