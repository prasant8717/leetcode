class Solution {
public:
    int func(int x) {
        string s = to_string(x);
        int n = s.size();
        if (n & 1)
            return 0;
        int a = 0;
        int b = 0;
        for (int i = 0; i < (n >> 1); ++ i) {
            a += s[i] - '0';
            b += s[n / 2 + i] - '0';
        }
        return a == b ? 1 : 0;
    }
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int x = low; x <= high; ++ x)
            res += func(x);
        return res;
    }
};
