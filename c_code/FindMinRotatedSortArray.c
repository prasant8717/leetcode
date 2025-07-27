int findMin(int* nums, int numsSize) {
    int l = 0;
    int r = numsSize - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] < nums[r]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l];
}
