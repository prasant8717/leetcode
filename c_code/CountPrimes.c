int countPrimes(int n) {
    bool *p = (bool *)malloc(n);
    memset(p, true, n);
    for (int i = 2; i * i < n; ++ i) {
        if (p[i] == true) {
            for (int j = i * i; j < n; j += i)
                p[j] = false;
        }
    }
    int cnt = 0;
    for (int i = 2; i < n; ++ i)
        if (p[i] == true)
            ++ cnt;
    return cnt;
}
