int findDuplicate(int* nums, int numsSize) {
    int *map = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++ i)
        map[i] = 0;
    for (int i = 0; i < numsSize; ++ i)
        map[nums[i]] ++;
    int res = 0;
    for (; res < numsSize; ++ res) {
        if (map[res] > 1)
            break;
    }
    free(map);
    return res;
}
