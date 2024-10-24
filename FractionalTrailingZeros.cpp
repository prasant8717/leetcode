class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5) {
            return 0;
        }
        int zeros = 0;
        for (int i = n; i > 0;) {
            i /= 5;
            zeros += i;
        }
        return zeros;
    }
};
