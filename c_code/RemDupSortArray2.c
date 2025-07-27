int removeDuplicates(int* nums, int numsSize) {
    int idx = 0;
    int dd = 0;
    for (int i = 1; i < numsSize; ++ i) {
        if (nums[idx] != nums[i]) {
            ++ idx;
            nums[idx] = nums[i];
            dd = 1;
        } else {
            if ((dd == 1) || (idx == 0)) {
                idx ++;
                nums[idx] = nums[i];
                dd = 0;
            }
        }
    }
    return idx + 1;
}
