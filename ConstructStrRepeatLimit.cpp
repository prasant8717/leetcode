class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string out;
        int c[26] = {0};
        int l = s.size();
        for (int i = 0; i < l; ++ i) {
            c[s[i] - 'a'] ++;
        }
        int k = 24;
        for (int i = 25; i >= 0; -- i) {
            if (k > i - 1)
                k = i - 1;
            while (1) {
                int j = repeatLimit;
                if (j > c[i])
                    j = c[i];
                for (; j > 0; -- j) {
                    out += 'a' + i;
                    c[i] --;
                }
                if (c[i] == 0)
                    break;
                while ((k >= 0) && (c[k] == 0))
                    k --;
                if (k < 0)
                    break;
                out += 'a' + k;
                c[k] --;
            }
        }
        return out;
    }
};
