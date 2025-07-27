bool isPalindrome(char* s) {
    int len = strlen(s);
    char *out = (char *)malloc(len + 1);
    int out_len = 0;
    for (int i = 0; i < len; ++ i) {
        char ch = tolower(*s);
        if (((ch <= 'z') && (ch >= 'a')) ||
            ((ch >= '0') && (ch <= '9'))) {
            out[out_len] = ch;
            out_len ++;
        }
        s ++;
    }
    out[out_len] = '\0';
    if (out_len <= 1) {
        return true;
    }
    int start = 0;
    int end = out_len - 1;
    while (start < end) {
        if (out[start] != out[end]) {
            return false;
        }
        start ++;
        end --;
    }
    free(out);
    return true;
}
