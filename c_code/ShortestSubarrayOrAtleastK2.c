int minimumSubarrayLength(int* nums, int numsSize, int k) {
    if (nums[0] >= k) {
        return 1;
    }
    int min = INT_MAX;
    int orv = 0;
    int cnt[32];
    for (int i = 0; i < 32; ++ i)
        cnt[i] = 0;
    int idx = 0;
    for (int i = 0; i < numsSize; ++ i) {
        orv |= nums[i];
        for (int j = 0; j < 32; ++ j) {
            if (((nums[i] >> j) & 1) == 1) {
                    ++ cnt[j];
            }
        }
        for (; (orv >= k) && (idx <= i); ++ idx) {
            if (min > (i - idx + 1))
                min = i - idx + 1;
            for (int j = 0; j < 32; ++ j) {
                if (((nums[idx] >> j) & 1) == 1) {
                    -- cnt[j];
                    if (cnt[j] == 0) {
                        orv ^= 1 << j;
                    }
                }
            }
        }
    }
    return min != INT_MAX ? min : -1;
}
