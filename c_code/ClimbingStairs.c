int climbStairs(int n) {
    int n0 = 1;
    int n1 = 1;
    int n2 = 0;
    if (n < 2)
        n2 = 1;
    else {
        for (int i = 2; i <= n; ++ i) {
            n2 = n1 + n0;
            n0 = n1;
            n1 = n2;
        }
    }
    return n2;
}
