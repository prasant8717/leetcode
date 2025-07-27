int gcd(int a, int b)
{
    int x = a > b ? a : b;
    int y = a < b ? a : b;
    int r = y;
    while(x % y)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return r;
}
char* gcdOfStrings(char* str1, char* str2) {
    int l1 = strlen(str1);
    int l2 = strlen(str2);

    int len = gcd(l1, l2);
    char *res = (char *)malloc(len + 1);
    int ll = l1;
    if (l1 < l2)
    {
        ll = l2;
    }
    for (int i = 0; i < ll; ++i)
    {
        if (i < len)
        {
            if (str1[i] != str2[i])
            {
                return "";
            }
            res[i] = str1[i];
        }
        else
        {
            if (i < l1)
            {
                if (str1[i] != res[i % len])
                {
                    return "";
                }
            }
            if (i < l2)
            {
                if (str2[i] != res[i % len])
                {
                    return "";
                }
            }
        }
        res[len] = '\0';
    }
    return res;
}
