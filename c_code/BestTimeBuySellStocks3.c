int maxProfit(int* prices, int pricesSize) {
    int b1 = INT_MIN;
    int b2 = INT_MIN;
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < pricesSize; ++ i) {
        if (s2 < b2 + prices[i]) {
            s2 = b2 + prices[i];
        }
        if (b2 < s1 - prices[i]) {
            b2 = s1 - prices[i];
        }
        if (s1 < b1 + prices[i]) {
            s1 = b1 + prices[i];
        }
        if (b1 < 0 - prices[i]) {
            b1 = 0 - prices[i];
        }
    }
    return s2;    
}
