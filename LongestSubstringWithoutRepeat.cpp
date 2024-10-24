int lengthOfLongestSubstring(char* s) {
    if (strlen(s) == 0)
        return 0;
    if (strlen(s) == 1)
        return 1;
    int maxLength = 0;
    bool visited[256];
    for (int i = 0; i < 256; ++ i) {
        visited[i] = false;
    }
    int left = 0, right = 0;
    while (right < strlen(s)) {
        while (visited[s[right]] == true) {
                visited[s[left]] = false;
                left++;
           }
        visited[s[right]] = true;
        if (maxLength < right -left + 1)
            maxLength = (right - left + 1);
        right++;
    }
    return maxLength;
}
