/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *out = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize - 1; ++ i) {
        for (int j = i + 1; j < numsSize; ++ j) {
            if (target == nums[i] + nums[j]) {
                out[0] = i;
                out[1] = j;
                return out;
            }
        }
    }
    return NULL;
}
