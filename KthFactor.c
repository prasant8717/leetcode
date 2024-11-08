int kthFactor(int n, int k) {
    int fc = 1;
    int f[n + 1];
    for (int i = 0; i <= n; ++ i)
        f[i] = -1;
    int c = 0;
    for (; fc <= n; ++ fc) {
        if (n % fc == 0) {
            f[c ++] = fc;
        }
    }
    return f[k - 1];
}
