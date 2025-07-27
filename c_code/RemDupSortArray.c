int removeDuplicates(int* nums, int numsSize) {
    int idx = 0;
    for (int i = 1; i < numsSize; ++ i) {
        if (nums[idx] != nums[i]) {
            ++ idx;
            nums[idx] = nums[i];
        }
    }
    return idx + 1;
}
