int maxProfit(int* prices, int pricesSize) {
    int max = 0;
    int res = prices[0];
    for(int i = 1; i < pricesSize; ++ i) {
        if (res > prices[i]) {
            res = prices[i];
            continue;
        }
        if (max < (prices[i] - res)) {
            max = prices[i] - res;
        }
    }
    return max;    
}
