class Solution {
public:
    int bitwiseComplement(int n) {
        int msb = 0;
        for (int i = 30; i >= 0; -- i) {
            if (n & ( 1 << i)) {
                msb = i;
                break;
            }
        }
        long long t = (1 << (msb + 1)) - 1;
        return t - n; 
    }
};
