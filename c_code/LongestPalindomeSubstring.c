char* longestPalindrome(char* s) {
    int len = strlen(s);
    char *out = (char *)malloc(len + 1);
    if (len == 0) {
        out[0] = '\0';
        return out;
    }
    int start = 0, end = 1;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= 1; j++) {
            int l = i;
            int r = i + j; 
            while ((l >= 0) && (r < len) && (s[l] == s[r])) {
                int tmp = r - l + 1;
                if (tmp > end) {
                    start = l;
                    end = tmp;
                }
                l--;
                r++;
            }
        }
    }
    strncpy(out, s + start, end);
    out[end] = '\0';
    return out;
}
