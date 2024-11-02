char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int l = 0;
    int r = lettersSize;
    while (l < r) {
        int m = (l + r) / 2;
        if (letters[m] <= target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return letters[l % lettersSize];
}
