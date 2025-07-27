int isprime(int n) {
    int sts;
    if (n == 1)
        sts = 0;
    else if (n < 4)
        sts = 1;
    else {
        int i = 2;
        for (; (i * i) <= n; ++ i)
            if (n % i == 0) {
                sts = 0;
                break;
            }
        if ((i * i) > n)
            sts = 1;
    }
    return sts;
}
int ispalindrome(int n) {
    int rev = 0;
    int t = n;
    while (t != 0) {
        rev = (rev * 10) + (t % 10);
        t /= 10;
    }
    int ret = 0;
    if (rev == n)
        ret = 1;
    return ret;
}
int primePalindrome(int n) {
    int res = 0;
    while (true) {
        if (isprime(n) == 1) {
            if (ispalindrome(n) == 1) {
                res = n;
                break;
            }
        }
        if ((n > 10000000) && (n < 100000000))
            n = 100000000;
        ++ n;
    }
    return res;
}
