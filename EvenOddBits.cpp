class Solution {
public:
    vector<int> evenOddBit(int n) {
        int ev = 0;
        int od = 0;
        for (int i = 0; (i < 32) && n; ++ i) {
            if ((i % 2) && (n & 1))
                ++ od;
            if (!(i % 2) && (n & 1))
                ++ ev;
            n = (n >> 1);
        }
        return {ev, od};
    }
};
