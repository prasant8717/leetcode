int countDigitOne(int n) {
    int c = 0;
    for (long long p = 1; p <= n; p *= 10) {
        long long d = p * 10;
        int q = n / d;
        int r = n % d;
        if (q > 0)
            c += q * p;
        if (r >= p) {
            int t = r - p + 1;
            if (t > p)
                c += p;
            else
                c += t;
        }
    }
    return c;
}
