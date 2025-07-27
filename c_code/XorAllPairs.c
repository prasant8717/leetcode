int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int sum = 0;
    if (nums2Size % 2 == 1) {
        for (int i = 0; i < nums1Size; ++ i) {
            sum ^= nums1[i];
        }
    }
    if (nums1Size % 2 == 1) {
        for (int i = 0; i < nums2Size; ++ i) {
            sum ^= nums2[i];
        }
    }
    return sum;
}
