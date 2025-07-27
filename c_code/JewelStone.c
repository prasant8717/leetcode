int numJewelsInStones(char* jewels, char* stones) {
    int ls = strlen(stones);
    int res = 0;
    for (int i = 0; i < ls; ++ i) {
        if (strchr(jewels, stones[i]) != NULL)
            ++ res;
    }
    return res;
}
