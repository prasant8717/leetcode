int singleNonDuplicate(int* nums, int numsSize) {
    int l = 0;
    int r = numsSize - 1;
    while (l < r) {
        int m = (l + r) >> 1;
        if (nums[m] != nums[m ^ 1]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return nums[l];
}
