class Solution {
public:
    int construct(vector<int>& v, int i, vector<int>& p) {
        if (i > p[1])
            return 0;
        if (v[i] != -1)
            return v[i];
        long long t = 0;
        if ((i >= p[0]) && (i <= p[1]))
            t = 1;
        t += construct(v, i + p[2], p) + construct(v, i + p[3], p);
        t %= ((int)1e9 + 7);
        v[i] = t;
        return t;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> p = {low, high, zero, one};
        vector<int> v(high + 1, -1);
        return construct(v, 0, p);
    }
};
