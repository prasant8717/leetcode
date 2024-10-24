int firstMissingPositive(int* nums, int numsSize) {
    bool *found = (bool *)malloc(numsSize + 1);
    for (int i = 0; i < numsSize + 1; ++i)
    {
        found[i] = false;
    }
    for (int i = 0; i < numsSize; ++i)
    {
        if ((nums[i] > 0) && (nums[i] < numsSize + 1))
        {
            found[nums[i]] = true;
        }
    }
    for (int i = 1; i < numsSize + 1; ++i)
    {
        if (found[i] == false)
        {
            return i;
        }
    }
    return numsSize + 1;
}
