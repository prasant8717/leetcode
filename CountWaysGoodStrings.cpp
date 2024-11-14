class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> v(high + 1);
        v[0] = 1;
        int r = 0;
        for (int i = 1; i <= high; ++ i) {
            if (i >= zero)
                v[i] = (v[i] + v[i - zero]) % ((int)1e9 + 7);
            if (i >= one)
                v[i] = (v[i] + v[i - one]) % ((int)1e9 + 7);
            if (i >= low)
                r = (r + v[i]) % ((int)1e9 + 7);
        }
        return r;        
    }
};
