class Solution {
private:
    double game(vector<double>& vd, int i, int m, int n, int k) {
        if (i >= k) {
            return (i <= n) ? 1 : 0;
        }
        if (i == k - 1) {
            int t = n - k + 1;
            if (t > m)
                t = m;
            return t * 1.0 / m;
        }
        if (vd[i] != 0) {
            return vd[i];
        }
        double td = game(vd, i + 1, m, n, k);
        vd[i] = td + (td - game(vd, i + m + 1, m, n, k)) / m;
        return vd[i];
    }

public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> vd(k);
        return game(vd, 0, maxPts, n, k);
    }
};
