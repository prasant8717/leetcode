char* intToRoman(int num) {
    struct rnum {
        int val;
        char ch[3];
    };
    struct rnum rrnum[] = {
        {1000, "M"}, {900, "CM"},
        {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"},
        {5, "V"}, {4, "IV"}, {1, "I"},
    };
    char *out = (char *)malloc(100);
    int idx = 0;
    for (int i = 0; i < sizeof(rrnum) / sizeof(struct rnum); ++ i) {
        if (num == 0) {
            break;
        }
        while (num >= rrnum[i].val) {
            num = num - rrnum[i].val;
            for (int j = 0; j < strlen(rrnum[i].ch); ++ j) {
                out[idx + j] = rrnum[i].ch[j];
            }
            idx = idx + strlen(rrnum[i].ch);
        }
    }
    out[idx] = '\0';
    return out;
}
