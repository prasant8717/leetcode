class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long l = 0;
        long long r = 1LL * (a + b) * n;
        int c = lcm(a, b);
        while (l < r) {
            long long m = (l + r) >> 1;
            if ((m / a) + (m / b) - (m / c) >= n)
                r = m;
            else
                l = m + 1;
        }
        return l % ((int)1e9 + 7);
    }
};
