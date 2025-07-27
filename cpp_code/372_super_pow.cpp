class Solution {
private:
    int pow(long long t, int n) {
        int m = 1337;
        long long res = 1;
        for (; n; n >>= 1) {
            if (n & 1) {
                res = res * t % m;
            }
            t = t * t % m;
        }
        return (int) res;
    }
public:
    int superPow(int a, vector<int>& b) {
        int m = 1337;
        long long res = 1;
        for (int i = b.size() - 1; i >= 0; -- i) {
            res = res * pow(a, b[i]) % m;
            a = pow(a, 10);
        }
        return res;
    }
};
