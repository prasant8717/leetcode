int minimumLength(char* s) {
    int n = strlen(s);
    int c[26];
    memset(&c[0], 0, 26);
    for (int i = 0; i < n; ++ i)
        ++ c[s[i] - 'a'];
    int res = 0;
    for (int i = 0; i < 26; ++ i) {
        if (c[i] != 0)
            if (c[i] % 2)
                res ++;
            else
                res += 2;
    }
    return res;
}
