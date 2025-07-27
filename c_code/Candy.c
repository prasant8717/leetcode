int candy(int* ratings, int ratingsSize) {
    int *left = (int *)malloc(sizeof(int) * ratingsSize);
    int *right = (int *)malloc(sizeof(int) * ratingsSize);
    for (int i = 0; i < ratingsSize; ++ i) {
        left[i] = 1;
        right[i] = 1;
    }
    for (int i = 1; i < ratingsSize; ++ i) {
        if (ratings[i] > ratings[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
    }
    for (int i = ratingsSize - 2; i >= 0; -- i) {
        if (ratings[i] > ratings[i + 1]) {
            right[i] = right[i + 1] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < ratingsSize; ++ i) {
        if (left[i] > right[i]) {
            ans += left[i];
        } else {
            ans += right[i];
        }
    }
    free(right);
    free(left);
    return ans;
}
