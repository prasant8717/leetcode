class Solution {
private:
    int bits(int n) {
        int c = 0;
        for (; n > 0; n /= 10)
            c += pow(10, n % 10);
        return c;
    }

public:
    bool reorderedPowerOf2(int n) {
        int c = bits(n);
        for (int i = 0; i < 30; ++ i)
            if (bits(1 << i) == c)
                return true;
        return false;
    }
};
