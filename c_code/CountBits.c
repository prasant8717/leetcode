/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int get_set_bits(int n)
{
    int cnt = 0;
    while(n != 0)
    {
        cnt ++;
        n = n & (n - 1);
    }
    return cnt;
} 

int* countBits(int n, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * (n+1));

    if (res != NULL)
    {
        *returnSize = n + 1;
        for (int i = 0; i <= n; ++i)
        {
            res[i] = get_set_bits(i);
        }
    }
    else
    {
        *returnSize = 0;
    }
    return res;
}
