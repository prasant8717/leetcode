class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        vector<long long> vl(n + 1, 1);
        for (int i = 1; i <= n; ++ i)
            vl[i] = vl[i - 1] * i;
        long long res = 0;
        unordered_set<string> us;
        int b = pow(10, (n - 1) / 2);
        for (int i = b; i < b * 10; ++ i) {
            string s = to_string(i);
            string r = s;
            reverse(r.begin(), r.end());
            s += r.substr(n % 2);
            if (stoll(s) % k) {
                continue;
            }
            string t = s;
            ranges::sort(t);
            if (us.count(t))
                continue;
            us.insert(t);
            vector<int> c(10);
            for (int j = 0; j < t.length(); ++ j)
                c[t[j] - '0'] ++;
            long long rs = (n - c[0]) * vl[n - 1];
            for (int j = 0; j < 10; ++ j)
                rs /= vl[c[j]];
            res += rs;
        }
        return res;
    }
};
