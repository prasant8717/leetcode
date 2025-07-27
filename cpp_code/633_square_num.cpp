class Solution {
public:
    bool judgeSquareSum(int c) {
        unsigned int n = 0;
        for (n = 1; n * n < c; ++ n);
        unsigned int l = 0;
        unsigned int r = n;
        while (l <= r) {
            unsigned int t = (l * l) + (r * r);
            if (t < c)
                ++ l;
            else if (t > c)
                -- r;
            else
                return true;
        }
        return false;
    }
};
