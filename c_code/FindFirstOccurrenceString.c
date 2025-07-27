int strStr(char* haystack, char* needle) {
    int nlen = strlen(needle);
    int hlen = strlen(haystack);
    int i = 0;
    int j = 0;
    while (i < hlen) {
        while (j < nlen) {
            if (needle[j] != haystack[i + j]) {
                j = 0;
                break;
            } else {
                j ++;
            }
            if (j == nlen) {
                return i;
            }
        }
        ++ i;
    }
    return -1;
}
