long long minEnd(int n, int x) {
    long long res = x;
    n --;
    for (int i = 0; i < 31; ++ i) {
        if (((x >> i) & 1) ^ 1) {
            res |= (n & 1) << i;
            n >>= 1;
        }
    }
    res |= ((long long)n) << 31;
    return res;
}
