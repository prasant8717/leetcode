int mySqrt(int x) {
    if ((x == 0) || (x == 1))
    {
        return x;
    }
    int sqrt = 0;
    long l = 1;
    long r = x / 2;
    long mid;
    while (l <= r)
    {
        mid = (r + l) / 2;
        if (mid * mid == x)
        {
            sqrt = mid;
            break;
        }
        else if (mid * mid < x)
        {
            l = mid + 1;
            sqrt = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return sqrt;
}
