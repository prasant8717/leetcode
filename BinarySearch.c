int search(int* nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (target == nums[mid])
            return mid;
        if (target < nums[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
