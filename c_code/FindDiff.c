char findTheDifference(char* s, char* t) {
    int sum = 0;
    while (*s != '\0') {
        sum += *t;
        sum -= *s;
        ++ t;
        ++ s;
    }
    return sum + *t;
}
