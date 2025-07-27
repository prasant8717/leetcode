int bit_count(int n) {
    int cnt = 0;
    while (n) {
        cnt ++;
        n = (n - 1) & n;
    }
    return cnt;
}
bool canSortArray(int* nums, int numsSize) {
    int max = 0;
    int i = 0;
    while (i < numsSize) {
        int cnt = bit_count(nums[i]);
        int j = i + 1;
        int cmin = nums[i];
        int cmax = nums[i];
        while ((j < numsSize) && (bit_count(nums[j]) == cnt)) {
            if (cmin > nums[j])
                cmin = nums[j];
            if (cmax < nums[j])
                cmax = nums[j];
            j ++;
        }
        if (max > cmin) {
            return false;
        }
        max = cmax;
        i = j;
    }
    return true;    
}
