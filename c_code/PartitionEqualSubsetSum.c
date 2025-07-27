bool canPartition(int* nums, int numsSize) {
    if (numsSize == 1)
        return false;
    int sum = 0;
    for (int i = 0; i < numsSize; ++ i)
        sum += nums[i];
    if (sum % 2 == 0) {
        bool f[numsSize + 1][(sum >> 1) + 1];
        memset(f, false, sizeof(f));
        f[0][0] = true;
        for (int i = 1; i <= numsSize; ++ i) {
            for (int j = 0; j <= (sum >> 1); ++ j) {
                f[i][j] = f[i - 1][j] || ((j >= nums[i - 1]) && f[i - 1][j - nums[i - 1]]);
            }
        }
        return f[numsSize][sum >> 1];
    }
    return false;
}
