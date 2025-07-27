int reverse(int x){
    long long op = 0;
    int sign = 1;
    long long inp = x;
    if (inp < 0)
    {
        sign = -1;
        inp *= sign;
    }
    while (inp > 0)
    {
        int rem = inp % 10;
        op *= 10;
        if (op > 0x7fffffff)
        {
            return 0;
        }
        op += rem;
        inp = inp / 10;
    }
    int tmp = (int)op * sign;
    return tmp;
}
