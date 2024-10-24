void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 1) {
        return;
    }
    int rot = k;
    if (k > numsSize) {
        rot = k % numsSize;
    }
    int *left = (int *)malloc(sizeof(int) * rot);
    int *right = (int *)malloc(sizeof(int) * (numsSize - rot));
    for (int i = 0; i < rot; ++ i) {
        left[i] = nums[numsSize - rot + i];
    }
    for (int i = 0; i < numsSize - rot; ++ i) {
        right[i] = nums[i];
    }
    for (int i = 0; i < numsSize; ++ i) {
        if (i < rot) {
            nums[i] = left[i];
        } else {
            nums[i] = right[i - rot];
        }
    }
}
