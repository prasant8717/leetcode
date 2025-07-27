void reverseString(char* s, int sSize) {
    for (int i = 0; i < ((sSize + 1) >> 1); ++ i) {
        char c = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = c;
    }
}
