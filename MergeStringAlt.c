char * mergeAlternately(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    char *mstr = (char *)malloc(len1 + len2 + 1);
    int idx1 = 0;
    int idx2 = 0;
    for (int i = 0; i < len1 + len2;)
    {
        if (idx1 < len1)
        {
            mstr[i] = word1[idx1];
            idx1 ++;
            i ++;
        }
        if (idx2 < len2)
        {
            mstr[i] = word2[idx2];
            idx2 ++;
            i ++;
        }
    }
    mstr[len1 + len2] = '\0';
    return mstr;
}
