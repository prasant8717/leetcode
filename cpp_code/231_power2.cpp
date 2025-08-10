class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool sts = false;
        if (n > 0)
            sts = !(n & (n - 1));
        return sts;
    }
};
