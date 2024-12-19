class Solution {
public:
    int binaryGap(int n) {
        int res = 0;
        int p = 32;
        int c = 0;
        for (; n != 0; n >>= 1) {
            if (n & 1) {
                int t = c - p;
                if (res < t)
                    res = t;
                p = c;
            }
            ++ c;
        }
        return res;
    }
};
