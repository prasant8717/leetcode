bool isPowerOfTwo(int n) {
    bool res = false;
    if (n > 0)
    {
        if ((n & (n - 1)) == 0)
        {
            res = true;
        }
    }
    return res;
}
