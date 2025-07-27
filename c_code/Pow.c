double myPow(double x, int n) {
    double result = 1.0;
    int pow_sign = (n < 0) ? -1 : 1;
    long long ex = (long long)n * pow_sign;
    double tmp = 1;
    for (long long i = ex; i > 0; i = (i >> 1))
    {
        if (i & 1)
        {
            tmp *= x;
        }
        x = x * x;
    }
    if (pow_sign == 1)
    {
        result = tmp;
    }
    else
    {
        result = result / tmp;
    }
    return result;
}
