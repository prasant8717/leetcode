class Solution {
public:
    bool isPowerOfFour(int n) {
        bool sts = false;
        if (n == 1)
            sts = true;
        else if (n > 1) {
#if 0
            while (n > 0) {
                if (n == 4) {
                    sts = true;
                    break;
                } else if (n & 3) {
                    sts = false;
                    break;
                }
                n >>= 2;
            }
#endif
#if 1
            int ob = n & 0x55555555;
            int eb = n & 0xaaaaaaaa;
            if (eb != 0)
                sts = false;
            else
                if ((ob & (ob - 1)) == 0)
                    sts = true;
#endif
        }
        return sts;
    }
};
