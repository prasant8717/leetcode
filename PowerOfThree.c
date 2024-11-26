bool isPowerOfThree(int n) {
    if (n <= 0)
        return false;
    for (int i = n; n > 1; n /= 3)
        if (n % 3)
            return false;
    return true;
}
