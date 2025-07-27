class Solution {
private:
    bool base10(long long n) {
        string s;
        while (n != 0) {
            s += '0' + n % 10;
            n /= 10;
        }
        int i = 0;
        int j = s.size() - 1;
        while ((i < j) && (s[i] == s[j])) {
            ++ i,
            -- j;
        }
        return i >= j;
    }

    long long kbase(int t, int k, bool b) {
        long long res = t;
        if (b == true)
            t /= k;
        while (t != 0) {
            res = (res * k) + (t % k);
            t /= k;
        }
        return res;
    }

public:
    long long kMirror(int k, int n) {
        long long res = 0;
        for (int i = 1; true; ++ i) {
            for (int t = pow(k, i - 1); t < pow(k, i); ++ t) {
                long long l = kbase(t, k, true);
                if (base10(l)) {
                    res += l;
                    if (-- n == 0)
                        return res;
                }
            }
            for (int t = pow(k, i - 1); t < pow(k, i); ++ t) {
                long long l = kbase(t, k, false);
                if (base10(l)) {
                    res += l;
                    if (-- n == 0)
                        return res;
                }
            }
        }
    }
};
