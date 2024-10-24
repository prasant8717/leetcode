int findKthLargest(int* nums, int numsSize, int k) {
    int idx = 0;
    while (idx < k)
    {
        for (int j = idx; j < numsSize; ++j)
        {
            if (nums[idx] < nums[j])
            {
                int tmp = nums[j];
                nums[j] = nums[idx];
                nums[idx] = tmp;
            }
        }
        idx ++;
    }
    return nums[k-1];
}
