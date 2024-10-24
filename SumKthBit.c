int sumIndicesWithKSetBits(int* nums, int numsSize, int k){
    int sum = 0;
    int num_bits[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
    for (int i = 0; i < numsSize; ++i)
    {
        int cnt = 0;
        int ii = i;
        while(ii)
        {
            cnt += num_bits[ii & 0xF];
            ii = (ii >> 4);
        }
        if (cnt == k)
        {
            sum += nums[i];
        }
    }
    return sum;
}
