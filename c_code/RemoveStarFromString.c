char* removeStars(char* s) {
    char *res = (char *)malloc(strlen(s) + 1);
    int top = 0;
    while(*s != '\0')
    {
        if (s[0] == '*')
        {
            top --;
        }
        else
        {
            res[top] = s[0];
            top ++;
        }
        s++;
    }
    res[top] = '\0';
    return res;
}
