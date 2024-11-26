bool isPowerOfFour(int n) {
    if (n <= 0)
        return false;
    if (n == 1)
        return true;
    while (n > 0) {
        if ((n & 3) != 0)
            return false;
        else if (n == 4)
            return true;
        n >>= 2;
    }
    return false;
}
