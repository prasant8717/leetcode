int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
    long long div = dividend;
    long long divd = divisor;
    div = llabs(div);
    divd = llabs(divd);
    long long q = 0;
    for (int i = 31; i >= 0; --i) {
        if ((divd << i) <= div) {
            div -= (divd << i);
            q |= (1LL << i);
        }
    }
    return (int)(q * sign);
}
