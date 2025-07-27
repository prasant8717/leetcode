class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long p = 0;
        long long m1 = 0;
        long long m2 = 0;
        for (int i = 0; i < differences.size(); ++ i) {
            p += differences[i];
            if (m1 > p)
                m1 = p;
            if (m2 < p)
                m2 = p;
        }
        long long t = (upper - lower) - (m2 - m1) + 1;
        int res = 0;
        if (t > 0)
            res = t;
        return res;
    }
};
