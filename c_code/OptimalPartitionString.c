int partitionString(char* s) {
    int res = 1;
    int mask = 0;
    for (int i = 0; i < strlen(s); ++ i) {
        int t = s[i] - 'a';
        if ((mask >> t) & 1) {
            ++ res;
            mask = 0;
        }
        mask |= (1 << t);
    }
    return res;    
}
