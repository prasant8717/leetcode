void sortColors(int* nums, int numsSize) {
    int cnt[3] = {0, 0, 0};
    for (int i = 0; i < numsSize; ++ i)
        cnt[nums[i]] ++;
    int j = 0;
    for (int i = 0; i < 3; ++ i) {
        for (int k = 0; k < cnt[i]; ++ k) {
            nums[j + k] = i;
        }
        j += cnt[i];
    }
}
