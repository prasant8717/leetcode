bool canJump(int* nums, int numsSize) {
    if (numsSize == 1) {
        return true;
    }
    if (nums[0] == 0) {
        return false;
    }
    int start = 0;
    int end = numsSize - 1;
    bool *vis = (bool *)malloc(sizeof(bool) * numsSize);
    vis[0] = true;
    for (int i = 1; i < numsSize; ++ i) {
        vis[i] = false;
    }
    while (start < end) {
        int step = nums[start];
        if ((step == 1) && (nums[start + 1] == 0)) {
            if (start != end - 1) {
                start ++;
                continue;
            }
        }
        for (int i = 1; i <= step; ++ i) {
            if (start + i <= end) {
                vis[start + i] = true;
            } else {
                break;
            }
        }
        start ++;
    }
    for (int i = 0; i < numsSize; ++ i) {
        if (vis[i] == false) {
            return false;
        }
    }
    return true;
}
