class Solution {
public:
    int findNthDigit(int n) {
        int a = 1;
        int b = 9;
        while (1LL * a * b < n) {
            n -= a * b;
            ++ a;
            b *= 10;
        }
        int c = pow(10, a - 1) + (n - 1) / a;
        int t = (n - 1) % a;
        return to_string(c)[t] - '0';
    }
};
