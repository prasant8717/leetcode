int trap(int* height, int heightSize) {
    int res = 0;
    int left = 0;
    int right = heightSize - 1;
    int max_left = 0;
    int max_right = 0;
    while (left <= right)
    {
        if (max_left <= max_right)
        {
            int tmp = max_left - height[left];
            if (tmp > 0)
            {
                res += tmp;
            }
            if (height[left] > max_left)
            {
                max_left = height[left];
            }
            left += 1;
        }
        else
        {
            int tmp = max_right - height[right];
            if (tmp > 0)
            {
                res += tmp;
            }
            if (height[right] > max_right)
            {
                max_right = height[right];
            }
            right -= 1;
        }
    }
    return res;
}
