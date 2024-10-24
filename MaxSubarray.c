int maxSubArray(int* nums, int numsSize) {
    int max = INT_MIN;
    int cmax = 0;
    for (int i = 0; i < numsSize; ++ i) {
        if (cmax + nums[i] > nums[i]) {
            cmax = cmax + nums[i];
        } else {
            cmax = nums[i];
        }
        if (max < cmax) {
            max = cmax;
        }
    }
    return max;
}
