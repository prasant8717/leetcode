class Solution {
public:
    bool isPowerOfThree(int n) {
        int sts = false;
        long s = 1;
        for (;;) {
            if (s < n) {
                s *= 3;
            } else {
                if (s == n)
                    sts = true;
                break;
            }
        }
        return sts;
    }
};
