char *itoa(int num, char *str1)
{
    char str[5] = {'\0'};
    int i = 0;
    while(num)
    {
        str[i] = 0x30 + (num % 10);
        ++ i;
        num = num / 10;
    }
    for (int j = i - 1; j >= 0; --j)
    {
        *str1 = str[j];
        str1 ++;
    }
    *str1 = '\0';
    str1 = str1 - i;
    return str1;
}

int compress(char* chars, int charsSize) {
    char *res = (char *)malloc(charsSize);
    char *const str1 = (char *)malloc(5);
    char tmp = chars[0];
    res[0] = tmp;
    int len = 1;
    int cnt = 1;
    for (int i = 1; i < charsSize; ++i)
    {
        if (tmp == chars[i])
        {
            cnt ++;
        }
        else
        {
            tmp = chars[i];
            if (cnt > 1)
            {
                char *str = itoa(cnt, str1);
                strncpy(res+len, str, strlen(str));
                len += strlen(str);
            }
            res[len] = tmp;
            len ++;
            cnt = 1;
        }
    }
    if (cnt > 1)
    {
        char *str = itoa(cnt, str1);
        strncpy(res+len, str, strlen(str));
        len += strlen(str);
    }
    strncpy(chars, res, len);
    free(str1);
    free(res);
    if (len < charsSize)
    {
        chars[len] = '\0';
    }
    return len;
}
