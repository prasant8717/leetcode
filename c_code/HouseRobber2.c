int rob(int* nums, int numsSize) {
    if (numsSize == 1)
        return nums[0];
    if (numsSize == 2)
        return nums[0] < nums[1] ? nums[1] : nums[0];
    int n0 = 0;
    int n1 = 0;
    int n2 = nums[0];
    for (int i = 1; i < numsSize - 1; ++ i) {
        if (nums[i] + n1 > n2)
            n0 = nums[i] + n1;
        else
            n0 = n2;
        n1 = n2;
        n2 = n0;
    }
    int max = n0;
    n0 = 0;
    n1 = 0;
    n2 = nums[1];
    for (int i = 2; i < numsSize; ++ i) {
        if (nums[i] + n1 > n2)
            n0 = nums[i] + n1;
        else
            n0 = n2;
        n1 = n2;
        n2 = n0;
    }
    if (max < n0)
        max = n0;
    return max;
}
