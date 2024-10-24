int singleNumber(int* nums, int numsSize) {
    int sum = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        sum = sum ^ nums[i];
    }
    return sum;
}
