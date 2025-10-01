class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int k = res;
        while (k >= numExchange) {
            int t = (k / numExchange);
            res += t;
            t += (k % numExchange);
            k = t;
        }
        return res;
    }
};
