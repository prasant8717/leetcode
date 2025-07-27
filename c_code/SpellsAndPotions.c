/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    *returnSize = spellsSize;
    int *op = (int *)malloc(sizeof(int) * spellsSize);
    for (int i = 0; i < spellsSize; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < potionsSize; ++j)
        {
            long long tmp = (long long)potions[j] * spells[i];
            if (tmp >= success)
            {
                cnt ++;
            }
        }
        op[i] = cnt;
    }
    return op;
}
