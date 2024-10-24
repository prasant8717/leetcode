__inline__ bool is_vowel(char c)
{
    bool sts = false;
    char ch = toupper(c);
    if ((ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U'))
    {
        sts = true;
    }
    return sts;
}

char* reverseVowels(char* s) {
    int len = strlen(s);
    int begin = 0;
    int end = len - 1;
    while (begin < end)
    {
        if ((is_vowel(s[begin]) == true) && (is_vowel(s[end]) == true))
        {
            if (s[begin] != s[end])
            {
                char tmp = s[begin];
                s[begin] = s[end];
                s[end] = tmp;
            }
            begin ++;
            end --;
        }
        else
        {
            if (is_vowel(s[begin]) == false)
            {
                begin ++;
            }
            if (is_vowel(s[end]) == false)
            {
                end --;
            }
        }
    }
    return s;
}
