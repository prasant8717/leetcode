bool increasingTriplet(int* nums, int numsSize) {
    if (numsSize < 3)
    {
        return false;
    }
    int *min_nums = (int *)malloc(sizeof(int) * numsSize);
    int min = 0;
    min_nums[min] = -1;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] <= nums[min])
        {
            min = i;
            min_nums[i] = -1;
        }
        else
        {
            min_nums[i] = i;
        }
    }
    int *max_nums = (int *)malloc(sizeof(int) * numsSize);
    int max = numsSize - 1;
    max_nums[max] = -1;
    for (int i = numsSize - 2; i >= 0; --i)
    {
        if (nums[i] >= nums[max])
        {
            max = i;
            max_nums[i] = -1;
        }
        else
        {
            max_nums[i] = i;
        }
    }
    for (int i = 0; i < numsSize; ++i)
    {
        if ((min_nums[i] != -1) && (max_nums[i] != -1))
        {
            return true;
        }
    }
    return false;
}
