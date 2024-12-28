int smallestRangeI(int* nums, int numsSize, int k) {
    int min = 10001;
    int max = -10001;
    for (int i = 0; i < numsSize; ++ i) {
        if (min > nums[i])
            min = nums[i];
    }
    for (int i = 0; i < numsSize; ++ i) {
        if (max < nums[i])
            max = nums[i];
    }
    int t = (max - min) - (k << 1);
    if (t < 0)
        t = 0;
    return t;
}
