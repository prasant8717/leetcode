class Solution {
private:
    int get_result(vector<int>& v, int f) {
        int m = 1e9 + 7;
        return accumulate(v.end() - f, v.end(), 0,
                      [&](int a, int b) { return (a + b) % m; });
    }

public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> v(n);
        long long t = 0;
        int m = 1e9 + 7;
        v[0] = 1;
        for (int i = 1; i < n; ++ i) {
            if ((i - delay) >= 0)
                t += v[i - delay];
            if ((i - forget) >= 0)
                t -= v[i - forget];
            t += m;
            t %= m;
            v[i] = t;
        }
        return get_result(v, forget);
    }
};
