int firstUniqChar(char* s) {
    int f[26];
    for (int i = 0; i < 26; ++ i)
        f[i] = -1;
    int res = 0;
    while (s[res] != '\0') {
        int t = s[res] - 'a';
        if (f[t] == -1)
            f[t] = res;
        else if (f[t] >= 0)
            f[t] = -2;
        ++ res;
    }
    for (int i = 0; i < res; ++ i) {
        int t = f[s[i] - 'a'];
        if (t >= 0)
            return t;
    }
    return -1;
}
