class Solution {
private:
    int mod = 1e9 + 7;
    long long pow(long l, int k) {
        long res = 1;
        while (k != 0) {
            if ((k & 1) == 1) {
                res = (res * l) % mod;
            }
            k >>= 1;
            l = (l * l) % mod;
        }
        return res;
    }

public:
    int countGoodArrays(int n, int m, int k) {
        int mx = 10;
        if (m < n)
            mx += n;
        else
            mx += m;
        long long ar[mx + 10];
        long long br[mx + 10];
        ar[0] = 1;
        br[0] = 1;
        for (int i = 1; i < mx; ++ i) {
            ar[i] = (ar[i - 1] * i) % mod;
            br[i] = pow(ar[i], mod - 2);
        }
        long long res = (((ar[n - 1] * br[k]) % mod) * br[n - 1 - k]) % mod;
        return (((res * m) % mod) * pow(m - 1, n - k - 1)) % mod;
    }
};
