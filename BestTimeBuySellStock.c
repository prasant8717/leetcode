int maxProfit(int* prices, int pricesSize) {
    int max = 0;
    int cur_max = 0;
    int res = prices[0];
    for(int i = 1; i < pricesSize; ++ i) {
        if (res > prices[i]) {
            res = prices[i];
            continue;
        }
        if (cur_max < (prices[i] - res)) {
            cur_max = prices[i] - res;
            max += cur_max;
            cur_max = 0;
            res = prices[i];
        }
    }
    return max;
}
