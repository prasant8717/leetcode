long long minEnd(int n, int x) {
    n --;
    long long res = x;
    for (int i = 0; i < 31; ++ i) {
        if (((x >> i) & 1) ^ 1) {
            res |= (n & 1) << i;
            n >>= 1;
        }
    }
    res |= (1LL * n) << 31;
    return res;
}
