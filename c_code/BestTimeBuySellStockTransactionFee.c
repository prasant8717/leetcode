int maxProfit(int* prices, int pricesSize, int fee) {
    long long min = INT_MIN;
    int out = 0;
    for (int i = 0; i < pricesSize; ++ i) {
        long long max = out;
        if (min + prices[i] - fee > out) {
            out = min + prices[i] - fee;
        }
        if (max - prices[i] > min) {
            min = max - prices[i];
        }
    }
    return out;
}
