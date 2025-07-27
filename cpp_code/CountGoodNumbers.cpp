class Solution {
public:
    long long qpow(long long x, long long n) {
        long long res = 1;
        int m = 1e9 + 7;
        while (n) {
            if ((n & 1) == 1)
                res = (res * x) % m;
            x = (x * x) % m;
            n >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        int m = 1e9 + 7;
        return qpow(5, (n + 1) >> 1) * qpow(4, n >> 1) % m;
    }
};
