bool isPerfectSquare(int num) {
    if (num < 0)
        return false;
    if (num <= 1)
        return true;
    int n = num / 2;
    for (int i = n; i > 0; i --) {
        if (((long long)i * i) == num)
            return true;
    }
    return false;    
}
