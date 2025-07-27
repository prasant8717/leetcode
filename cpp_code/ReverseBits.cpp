class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if ((n == 0) || (n == 0xFFFFFFFF)) {
            return n;
        }
        int out = 0;
        for (int i = 0; i < 32; ++ i) {
            if ((n >> i) & 1) {
                out |= (1 << (31 - i));
            }
        }
        return out;
    }
};
