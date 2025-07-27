int peakIndexInMountainArray(int* arr, int arrSize) {
    int l = 0;
    int r = arrSize - 1;
    while (l < r) {
        int m = (l + r) >> 1;
        if (arr[m] < arr[m + 1])
            l = m + 1;
        else
            r = m;
    }
    return l;
}
