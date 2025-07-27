int longestSubarray(int* nums, int numsSize) {
    int l = 0;
    int r = 0;
    int max = 0;
    int del = 1;

    while (r < numsSize)
    {
        if (nums[r] == 0)
        {
            del --;
        }
        r ++;
        while (del < 0)
        {
            if (nums[l] == 0)
            {
                del ++;
            }
            l ++;
        }
        int tmp = r - l;
        if (max < tmp)
        {
            max = tmp;
        }
    }
    return max - 1;
}
