/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
    int m1 = 0;
    int m2 = 0;
    int id1 = 0;
    int id2 = 0;
    int id3 = 0;
    int s0 = 0;
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    int *res = (int *)malloc(3 * sizeof(int));
    *returnSize = 3;
    for (int i = k * 2; i < numsSize; ++ i) {
        s1 += nums[i - k * 2];
        s2 += nums[i - k];
        s3 += nums[i];
        if (i >= k * 3 - 1) {
            if (s1 > m1) {
                m1 = s1;
                id1 = i - k * 3 + 1;
            }
            if (m1 + s2 > m2) {
                m2 = m1 + s2;
                id2 = id1;
                id3 = i - k * 2 + 1;
            }
            if (m2 + s3 > s0) {
                s0 = m2 + s3;
                res[0] = id2;
                res[1] = id3;
                res[2] = i - k + 1;
            }
            s1 -= nums[i - k * 3 + 1];
            s2 -= nums[i - k * 2 + 1];
            s3 -= nums[i - k + 1];
        }
    }
    return res;
}
