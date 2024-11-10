int numDecodings(char* s) {
    int l = strlen(s);
    int *cnt = (int *)malloc(sizeof(int) * (l + 1));
    memset(cnt, 0, sizeof(int) * (l + 1));
    cnt[0] = 1;
    for (int i = 1; i <= l; ++ i) {
        if (s[i - 1] != '0') {
            cnt[i] = cnt[i - 1];
        }
        if ((i > 1) &&
            ((s[i - 2] == '1') ||
             ((s[i - 2] == '2') && (s[i - 1] < '7')))) {
                cnt[i] += cnt[i - 2];
            }
        }
        int res = cnt[l];
        free(cnt);
        return res;
}
