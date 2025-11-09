class Solution {
private:
    bool scan(vector<int> vs, int r, int as,
             long long mp) {
        int n = vs.size();
        long long t = accumulate(vs.begin(), vs.begin() + r, 0L);
        for (int i = 0; i < n; ++ i) {
            if (i + r < n)
                t += vs[i + r];
            if (t < mp) {
                long long tp = mp - t;
                if (tp > as)
                    return false;
                vs[min(n - 1, i + r)] += tp;
                as -= tp;
                t += tp;
            }
            if (i - r >= 0)
                t -= vs[i - r];
        }
        return true;
    }

public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long l = ranges::min(stations);
        long long rr = accumulate(stations.begin(), stations.end(), 0L) + k + 1;
        while (l < rr) {
            long long m = (l + rr) >> 1;
            if (scan(stations, r, k, m))
                l = m + 1;
            else
                rr = m;
        }
        return l - 1;
    }
};

