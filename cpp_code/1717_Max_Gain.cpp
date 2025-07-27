class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a = 'a';
        char b = 'b';
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }
        int res = 0;
        int c1 = 0;
        int c2 = 0;
        for (int i = 0; i < s.length(); ++ i) {
            if (s[i] == a) {
                c1 ++;
            } else if (s[i] == b) {
                if (c1 != 0) {
                    res += x;
                    c1 --;
                } else {
                    c2 ++;
                }
            } else {
                if (c1 < c2)
                    res += c1 * y;
                else
                    res += c2 * y;
                c1 = 0;
                c2 = 0;
            }
        }
        if (c1 < c2)
            res += c1 * y;
        else
            res += c2 * y;
        return res;
    }
};
