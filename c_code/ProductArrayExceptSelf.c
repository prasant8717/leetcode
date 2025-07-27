/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    //int *res = NULL;
    *returnSize = numsSize;
    int *res = (int *)malloc(sizeof(int) * numsSize);
    if (res != NULL)
    {
        res[0] = 1;
        for (int i = 1; i < numsSize; ++i)
        {
            res[i] = res[i - 1] * nums[i-1];
        }
        int right = nums[numsSize - 1];
        for (int i = numsSize - 2; i >= 0; i --)
        {
            res[i] *= right;
            right *= nums[i];
        }
    }
    else
    {
        *returnSize = 0;
    }
    return res;
}
