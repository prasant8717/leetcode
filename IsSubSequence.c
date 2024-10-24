bool isSubsequence(char* s, char* t) {
    bool res = false;
    int idx = 0;
    int slen = strlen(s);
    while(*s != '\0')
    {
        while(*t != '\0')
        {
            if (*s == *t)
            {
                idx ++;
                t ++;
                break;
            }
            t ++;
        }
        s ++;
    }
    if (idx == slen)
    {
        res = true;
    }
    return res;
}
