int arrangeCoins(int n) {
    int r = 1;
    while (true) {
        n = n - r;
        r ++;
        if (n < r)
            break;
    }
    return r != 1 ? r - 1 : 1;
}
