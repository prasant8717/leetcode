int findPeakElement(int* nums, int numsSize) {
    if (numsSize == 1)
    {
        return 0;
    }
    if (numsSize == 2)
    {
        if (nums[0] > nums[1])
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    int start = 0;
    int end = numsSize - 1;
    int pick = -1;
    while (start < end)
    {
        int middle = start + (end - start) / 2;
        if (start == middle)
        {
            break;
        }
        else
        {
            if ((nums[middle] > nums[middle + 1]) && (nums[middle] > nums[middle - 1]))
            {
                pick = middle;
                break;
            }
            else if (nums[middle] > nums[middle + 1])
            {
                end = middle;
            }
            else
            {
                start = middle;
            }
        }
    }
    if (pick == -1)
    {
        if (nums[0] > nums[1])
        {
            return 0;
        }
    }
    if (pick == -1)
    {
        if (nums[numsSize - 1] > nums[numsSize - 2])
        {
            return numsSize - 1;
        }
    }
    return pick;
}
