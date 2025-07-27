bool isNumber(char* s) {
    int l = strlen(s);
    int n = 0;
    if ((s[n] == '+') || (s[n] == '-'))
        ++ n;
    if (n == l)
        return false;
    if ((s[n] == '.') &&
        ((n + 1 == l) || (s[n + 1] == 'e') || (s[n + 1] == 'E'))) 
        return false;
    int d = 0;
    int e = 0;
    for (int i = n; i < l; ++ i) {
        if (s[i] == '.') {
            if (e || d)
                return false;
            ++ d;
        } else if ((s[i] == 'e') || (s[i] == 'E')) {
            if (e || (i == n) || (i == l - 1))
                return false;
            ++ e;
            if ((s[i + 1] == '+') || (s[i + 1] == '-')) {
                ++ i;
                if (i == l - 1)
                    return false;
            }
        } else if ((s[i] < '0') || (s[i] > '9'))
            return false;
    }
    return true;    
}
