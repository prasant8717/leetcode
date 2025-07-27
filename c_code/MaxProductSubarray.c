int maxProduct(int* nums, int numsSize) {
    int *pmax = (int *) malloc(sizeof(int) * numsSize);
    int *pmin = (int *) malloc(sizeof(int) * numsSize);
    pmax[0] = nums[0];
    pmin[0] = nums[0];
    int max = nums[0];
    for (int i = 1; i < numsSize; i ++) {
        int num = nums[i];
        if (num > 0) {
            pmax[i] = num;
            if (pmax[i] < pmax[i - 1] * num)
                pmax[i] = pmax[i - 1] * num;
            pmin[i] = num;
            if (pmin[i] > pmin[i - 1] * num)
                pmin[i] = pmin[i - 1] * num;
        } else {
            pmax[i] = num;
            if (pmax[i] < pmin[i - 1] * num)
                pmax[i] = pmin[i - 1] * num;
            pmin[i] = num;
            if (pmin[i] > pmax[i - 1] * num)
                pmin[i] = pmax[i - 1] * num;
        }
        if (max < pmax[i])
            max = pmax[i];
    }
    return max;
}
