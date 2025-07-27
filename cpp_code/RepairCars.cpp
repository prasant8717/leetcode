class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0;
        long long r = 1LL * ranks[0] * cars * cars;
        while (l < r) {
            long long m = (l + r) >> 1;
            long long c = 0;
            for (int i = 0; i < ranks.size(); ++ i)
                c += sqrt(m / ranks[i]);
            if (c >= cars)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
