int minimizeXor(int num1, int num2) {
    int cnt = 0;
    while (num2) {
        ++ cnt;
        num2 = num2 & (num2 - 1);
    }
    int res = 0;
    for (int i = 30; (i >= 0) && cnt; -- i) {
        if ((num1 >> i) & 1) {
            res |= 1 << i;
            -- cnt;
        }
    }
    for (int i = 0; cnt; ++ i) {
        if (((num1 >> i) & 1) ^ 1) {
            res |= 1 << i;
            -- cnt;
        }
    }
    return res;    
}
