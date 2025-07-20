class Solution {
public:
    int findComplement(int num) {
        int m = 1;
        for (;;)
            if (m < num) {
                m = (m << 1) | 1;
            } else {
                break;
            }
        return (num ^ m);
    }
};
