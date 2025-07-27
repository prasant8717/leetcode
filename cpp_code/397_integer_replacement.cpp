class Solution {
public:
    int integerReplacement(int n) {
        long long t = n;
        int c = 0;
        while (t != 1) {
            if ((t & 1) == 0) {
                t >>= 1;
            } else if ((t != 3) && ((t & 3) == 3)) {
                ++ t;
            } else {
                -- t;
            }
            ++ c;
        }
        return c;
    }
};
