int check(int n, int *v) {
    int a = n;
    int b = 0;
    int c = 1;
    while (a != 0) {
        int d = a % 10;
        if (v[d] == -1)
            return 0;
        b += v[d] * c;
        c *= 10;
        a /= 10;
    }
    if (n != b)
        return 1;
    else
        return 0;
}
int rotatedDigits(int n) {
    int v[] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
    int res = 0;
    for (int i = 1; i <= n; ++ i)
        res += check(i, &v[0]);
    return res;
}
