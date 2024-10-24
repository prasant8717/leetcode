/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    char max = 0;
    bool *res = (bool *)malloc(candiesSize);
    *returnSize = candiesSize;
    for (int i = 0; i < candiesSize; ++i)
    {
        if (candies[i] > max)
        {
            max = candies[i];
        }
    }
    for (int i = 0; i < candiesSize; ++i)
    {
        if (candies[i] +  extraCandies >= max)
        {
            res[i] = true;
        }
        else
        {
            res[i] = false;
        }
    }
    return res;
}
