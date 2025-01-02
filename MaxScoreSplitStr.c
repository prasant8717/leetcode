int maxScore(char* s) {
    int l = 0;
    int sz = strlen(s);
    int c = 0;
    for (int i = 0; i < sz; ++ i)
        if (s[i] == '1')
            ++ c;
    int res = 0;
    int r = c;
    for (int i = 0; i < sz - 1; ++ i) {
        l += (s[i] - '0') ^ 1;
        r -= s[i] - '0';
        if (res < l + r)
            res = l + r;
    }
    return res;
}
