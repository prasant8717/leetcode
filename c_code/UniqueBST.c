int numTrees(int n) {
    int *res = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; ++ i)
        res[i] = 0;
    res[0] = 1;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j < i; ++ j) {
            res[i] += res[j] * res[i - j - 1];
        }
    }
    int tmp = res[n];
    free(res);
    return tmp;    
}
