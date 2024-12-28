/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* s, int* returnSize) {
    int n = strlen(s);
    *returnSize = n + 1;
    int *out = (int *)malloc((n + 1) * sizeof(int));
    int max = n;
    int min = 0;
    for (int i = 0; i < n; ++ i) {
        if (s[i] == 'I') {
            out[i] = min;
            ++ min;
        } else {
            out[i] = max;
            -- max;
        }
    }
    if (s[n - 1] == 'I')
        out[n] = min;
    else
        out[n] = max;
    return out;
}
