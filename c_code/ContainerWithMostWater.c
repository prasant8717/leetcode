int maxArea(int* height, int heightSize) {
    int area = 0;
    int left = 0;
    int right = heightSize - 1;
    while(left < right)
    {
        int tmp = height[left];
        if (height[left] > height[right])
        {
            tmp = height[right];
        }
        int tmp_area = tmp * (right - left);
        if (area < tmp_area)
        {
            area = tmp_area;
        }
        if (height[left] < height[right])
        {
            left ++;
        }
        else
        {
            right --;
        }
    }
    return area;
}
