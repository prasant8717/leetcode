int jump(int* nums, int numsSize) {
    int jmp[numsSize];
    int i;
    int j;

    jmp[0] = 0;
    for (i = 1; i < numsSize; i++) {
        jmp[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if ((i <= j + nums[j]) && (jmp[j] != INT_MAX)) {
                if (jmp[i] > jmp[j] + 1)
                    jmp[i] = jmp[j] + 1;
                break;
            }
        }
    }
    return jmp[numsSize - 1];
}
