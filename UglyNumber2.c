int nthUglyNumber(int n) {
    int *r = (int *)malloc(sizeof(int) * n);
    memset(r, 0, sizeof(int) * n);
    r[0] = 1;
    int x = 0;
    int y = 0;
    int z = 0;
    int i = 1;
    while (i < n) {
        int t1 = r[x] * 2;
        int t2 = r[y] * 3;
        int t3 = r[z] * 5;
        int t = t1;
        if (t > t2)
            t = t2;
        if (t > t3)
            t = t3;
        if (t == t1)
            ++ x;
        if (t == t2)
            ++ y;
        if (t == t3)
            ++ z;
        r[i] = t;
        ++ i;
    }    
    return r[n - 1];
}
