char* getHint(char* secret, char* guess) {
    int x = 0;
    int c1[10];
    int c2[10];
    memset(&c1[0], 0, 10);
    memset(&c2[0], 0, 10);
    while (*secret != '\0') {
        char ch1 = *secret;
        char ch2 = *guess;
        if (ch1 == ch2) {
            x ++;
        } else {
            c1[ch1 - '0'] ++;
            c2[ch2 - '0'] ++;
        }
        ++ secret;
        ++ guess;
    }
    int y = 0;
    for (int i = 0; i < 10; ++ i) {
        if (c1[i] < c2[i])
            y += c1[i];
        else
            y += c2[i];
    }
    char *out = (char *)malloc(20);
    sprintf(out, "%dA%dB", x, y);
    return out;
}
