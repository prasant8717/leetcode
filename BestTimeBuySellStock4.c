int maxProfit(int k, int* prices, int pricesSize) {
    if (k >= pricesSize / 2) {
        int s = 0;
        int b = INT_MIN;
        for (int i = 0; i < pricesSize; ++ i) {
            if (b + prices[i] > s) {
                s = b + prices[i];
            }
            if (s - prices[i] > b) {
                b = s - prices[i];
            }
        }
        return s;
    }
    int *sp = (int *)malloc(sizeof(int) * (k + 1));
    int *bp = (int *)malloc(sizeof(int) * (k + 1));
    for (int i = 0; i <= k; ++ i) {
        sp[i] = 0;
        bp[i] = INT_MIN;
    }
    for (int i = 0; i < pricesSize; ++ i) {
        for (int j = k; j > 0; --j) {
            if (bp[j] + prices[i] > sp[j]) {
                sp[j] = bp[j] + prices[i];
            }
            if (sp[j - 1] - prices[i] > bp[j]) {
                bp[j] = sp[j - 1] - prices[i];
            }
        }
    }
    return sp[k];    
}
