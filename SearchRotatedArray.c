int search(int* nums, int numsSize, int target) {
    int pos = -1;
    int l = 0;
    int r = numsSize - 1;
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] >= nums[l])
        {
            if ((nums[mid] > target) && (nums[l] <= target))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if ((nums[mid] < target) && (nums[r] >= target))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return pos;
}
