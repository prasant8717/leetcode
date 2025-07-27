char* toHex(int num) {
    char *out = (char *)malloc(9);
    memset(out, 0, 9);
    char *str = "0123456789abcdef";
    int idx = 7;
    while (idx >= 0) {
        int t = num & 0xf;
        out[idx] = str[t];
        num >>= 4;
        if (num == 0)
            break;
        idx --;
    }
    return out + (idx < 0 ? 0 : idx);
}
