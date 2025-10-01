class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long k = 0; k <= 60; ++ k) {
            long long t = num1 - k * num2;
            if ((__builtin_popcountl(t) <= k) && (k <= t))
                return k;
        }
        return -1;
    }
};
