/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    *returnSize = ASize;
    int *out = (int *)malloc(ASize * sizeof(int));
    memset(out, 0, ASize * sizeof(int));
    int *ca = (int *)malloc((ASize + 1) * sizeof(int));
    memset(ca, 0, (ASize + 1) * sizeof(int));
    int *cb = (int *)malloc((ASize + 1) * sizeof(int));
    memset(cb, 0, (ASize + 1) * sizeof(int));
    for (int i = 0; i < ASize; ++ i) {
        ++ ca[A[i]];
        ++ cb[B[i]];
        for (int j = 1; j <= ASize; ++ j) {
            if (ca[j] < cb[j])
                out[i] += ca[j];
            else
                out[i] += cb[j];
        }
    }
    free(cb);
    free(ca);
    return out;
}
