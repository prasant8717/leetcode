class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0)
            return "0";
        int k = 1;
        string out;
        while (n != 0) {
            if (n % 2 != 0) {
                out += '1';
                n -= k;
            } else
                out += '0';
            k *= -1;
            n /= 2;
        }
        int l = out.size();
        for (int i = 0; i <= (l >> 1); ++ i) {
            char ch = out[i];
            out[i] = out[l - 1 - i];
            out[l - 1 - i] = ch;
        }
        return out;
    }
};
