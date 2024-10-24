int rob(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    int n1 = 0;
    int n2 = nums[0];
    int n0 = 0;
    for (int i = 1; i < numsSize; ++ i)
    {
        if (nums[i] + n1 > n2) {
            n0 = nums[i] + n1;
        }
        else {
            n0 = n2;
        }
        n1 = n2;
        n2 = n0;
    }
    return n0;
}
