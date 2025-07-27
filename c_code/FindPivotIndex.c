int pivotIndex(int* nums, int numsSize) {
    int pivot = -1;
    int left_sum = 0;
    int right_sum = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        right_sum += nums[i];
    }
    for (int i = 0; i < numsSize; ++i)
    {
        if (i != 0)
        {
            left_sum += nums[i - 1];
        }
        if (i != numsSize - 1)
        {
            right_sum -= nums[i];
        }
        else
        {
            right_sum = 0;
        }
        if (left_sum == right_sum)
        {
            pivot = i;
            break;
        }
    }
    return pivot;
}
