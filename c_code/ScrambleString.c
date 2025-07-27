int f[30][30][31];
bool scramble(int i, int j, int k, char *s1, char *s2) {
    if (f[i][j][k] != -1) {
        return f[i][j][k] == 1;
    }
    if (k == 1) {
        return s1[i] == s2[j];
    }
    for (int h = 1; h < k; ++ h) {
        if (scramble(i, j, h, s1, s2) && scramble(i + h, j + h, k - h, s1, s2)) {
            f[i][j][k] = 1;
            return true;
        }
        if (scramble(i + h, j, k - h, s1, s2) && scramble(i, j + k - h, h, s1, s2)) {
            f[i][j][k] = 1;
            return true;
        }
    }
    f[i][j][k] = 0;
    return false;
}
bool isScramble(char* s1, char* s2) {
    int ls = strlen(s1);
    memset(f, -1, sizeof(f));
    return scramble(0, 0, ls, s1, s2);    
}
