int findKOr(int* nums, int numsSize, int k) {
    int res = 0;
    for (int i = 0; i < 32; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < numsSize; ++j)
        {
            if (nums[j] & ((unsigned int)1 << i))
            {
                cnt ++;
                if (cnt >= k)
                {
                    res |= (1 << i);
                    break;
                }
            }
        }
    }
    return res;
}
