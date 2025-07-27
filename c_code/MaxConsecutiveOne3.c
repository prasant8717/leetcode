int longestOnes(int* nums, int numsSize, int k) {
    int max = 0;
    int l = 0;
    int r = 0;
    int zz = k;
    while (r < numsSize)
    {
        if (nums[r] == 0)
        {
            zz --;
        }
        r ++;

        while (zz < 0)
        {
            if (nums[l] == 0)
            {
                zz ++;
            }
            l ++;
        }
        int tmp = r - l;
        if (max < tmp)
        {
            max = tmp;
        }
    }
    return max;
}
