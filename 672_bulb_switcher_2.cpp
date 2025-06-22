class Solution {
public:
    int flipLights(int n, int presses) {
        if (n > 6)
            n = 6;
        vector<int> ops = {0x3f, 0x15, 0x2a, 0x24};
        unordered_set<int> us;
        for (int i = 0; i < 1 << 4; ++ i) {
            int c = __builtin_popcount(i);
            if (c > presses || c % 2 != presses % 2)
                continue;
            int t = 0;
            for (int j = 0; j < 4; ++ j) {
                if (i >> j & 1) {
                    t ^= ops[j];
                }
            }
            t &= (1 << 6) - 1;
            t >>= (6 - n);
            us.insert(t);
        }
        return us.size();
    }
};
