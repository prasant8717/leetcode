int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int i = len - 1;
    int cnt = 0;
    while (i >= 0) {
        if (s[i] == ' ') {
            if(cnt > 0)
                break;
        } else {
            cnt ++;
        }
        -- i;
    }
    return cnt;
}
