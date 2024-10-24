void moveZeroes(int* nums, int numsSize) {
    int *out = (int *)malloc(sizeof(int) * numsSize);
    int idx = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if(nums[i] != 0)
        {
            out[idx] = nums[i];
            idx ++;
        }
    }
    for (int i = idx; i < numsSize; ++i)
    {
        out[i] = 0;
    }
    for (int i = 0; i < numsSize; ++i)
    {
        nums[i] = out[i];
    }
    free(out);
}
