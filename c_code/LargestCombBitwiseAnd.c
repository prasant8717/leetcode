int bit_count(int n) {
    int cnt = 0;
    while (n) {
        cnt ++;
        n = n & (n - 1);
    }
    return cnt;
}
int bit_clz(int n) {
    int i = 23;
    for (; i >= 0; -- i) {
        if ((n & (1 << i)) != 0)
            break;
    }
    return 23 - i;
}
int largestCombination(int* candidates, int candidatesSize) {
    int max = INT_MIN;
    for (int i = 0; i < candidatesSize; ++ i) {
        if (max < candidates[i])
            max = candidates[i];
    }
    int m = 24 - bit_clz(max);
    int res = 0;
    for (int i = 0; i < m; ++ i) {
        int cnt = 0;
        for (int j = 0; j < candidatesSize; ++ j) {
            cnt += (candidates[j] >> i) & 1;
        }
        if (res < cnt)
            res = cnt;
    }
    return res;
}
