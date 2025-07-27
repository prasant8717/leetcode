class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.length();
        int lp = p.length();
        int i = 0;
        int j = 0;
        int idx = -1;
        int m = 0;
        while (i < ls) {
            if ((j < lp) && ((p[j] == '?') || (p[j] == s[i]))){          
                ++ i;
                ++ j;
            } else if ((j < lp) && (p[j] == '*')) {
                idx = j;
                m = i;
                ++ j;
            } else if (idx != -1) {
                j = idx + 1;
                ++ m;
                i = m;
            } else {
                return false;
            }
        }
        while ((j < lp) && (p[j] == '*')) {
            ++ j;
        }
        return j == lp;
    }
};
