class Solution {
public:
    int bitSetCount(int n) {
        int c = 0;
        while (n) {
            c ++;
            n = n & (n - 1);
        }
        return c;
    }
    int countPrimeSetBits(int left, int right) {
        int c = 0;
        for (int i = left; i <= right; ++ i) {
            int b = bitSetCount(i);
            if ((b == 2) || (b == 3) || (b == 5) || (b == 7) ||
                (b == 11) || (b == 13) || (b == 17) || (b == 19))
                    c ++;
        }
        return c;
    }
};
