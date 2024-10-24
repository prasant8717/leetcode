int tribonacci(int n){
    int num = 0;
    if (n == 1)
    {
        num = 1;
    }
    else if (n == 2)
    {
        num = 1;
    }
    else
    {
        int n0 = 0;
        int n1 = 1;
        int n2 = 1;
        for (int i = 3; i <= n; ++i)
        {
            num = n0 + n1 + n2;
            n0 = n1;
            n1 = n2;
            n2 = num;
        }
    }
    return num;
}
