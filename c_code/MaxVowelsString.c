__inline__ is_vowel(char ch)
{
    bool sts = false;
    if ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'))
    {
        sts = true;
    }
    return sts;
}

int maxVowels(char* s, int k) {
    int cnt = 0;
    int cc = 0;
    for (int i = 0; i < k; ++i)
    {
        if (is_vowel(s[i]) == true)
        {
            cc ++;
        }
    }
    int start = 0;
    int end = strlen(s);
    while(start + k <= end)
    {
        if (start > 0)
        {
            if (is_vowel(s[start - 1]) == true)
            {
                -- cc;
            }
            if (is_vowel(s[start + k - 1]) == true)
            {
                ++ cc;
            }
        }
        if (cnt < cc)
        {
            cnt = cc;
        }
        if (cnt == k)
        {
            break;
        }
        start ++;
    }
    return cnt;
}
