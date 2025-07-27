int romanToInt(char* s) {
    int *rnum = (int *)malloc(sizeof(int) * 128);
    rnum['I'] = 1;
    rnum['V'] = 5;
    rnum['X'] = 10;
    rnum['L'] = 50;
    rnum['C'] = 100;
    rnum['D'] = 500;
    rnum['M'] = 1000;
    int res = 0;
    for (int i = 0; i + 1 < strlen(s); ++ i) {
        if (rnum[s[i]] < rnum[s[i + 1]]) {
            res = res - rnum[s[i]];
        } else {
            res = res + rnum[s[i]];
        }
    }
    int tmp = rnum[s[strlen(s) - 1]];
    free(rnum);
    return res + tmp;
}
