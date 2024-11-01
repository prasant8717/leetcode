char* makeFancyString(char* s) {
    char *out = (char *)malloc(strlen(s) + 1);
    out[0] = s[0];
    int sz = 1;
    int cnt = 1;
    for (int i = 1; i < strlen(s); ++ i) {
        if (s[i] == out[sz - 1]) {
            cnt ++;
        } else {
            cnt = 1;
        }
        if (cnt < 3) {
            out[sz] = s[i];
            sz ++;
        }
    }
    out[sz] = '\0';
    return out;    
}
