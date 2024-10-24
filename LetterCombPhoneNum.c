/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    if ((len == 0) || (len > 4)) {
        *returnSize = 0;
        return NULL;
    }
    char *alph[] = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    int *digit = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; ++i) {
        digit[i] = digits[i] - 48;
    }
    char **out = malloc(257 * sizeof(char *));
    *returnSize = 0;
    char *que[257];
    int f = 0;
    int r = 0;
    que[r++] = "";
    while (f < r) {
        char *s = que[f++];
        if (strlen(s) == len) {
            out[*returnSize] = s;
            (*returnSize)++;
        } else {
            int idx = strlen(s);
            const char *alp = alph[digit[idx] - 2];
            for (int i = 0; alp[i] != '\0'; i++) {
                char *str = malloc(strlen(s) + 2);
                strcpy(str, s);
                str[strlen(s)] = alp[i];
                str[strlen(s) + 1] = '\0';
                que[r++] = str;
            }
        }
    }
    return out;
}
