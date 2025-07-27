int addDigits(int num) {
    int sum = 0;
    while (num > 0) {
        for (int i = num; i > 0; i /= 10) {
            sum += (i % 10);
        }
        if (sum >= 10) {
            num = sum;
            sum = 0;
        } else
            num = 0;
    }
    return sum;
}
