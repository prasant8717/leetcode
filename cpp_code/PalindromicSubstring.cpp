class Solution {
public:
    int count(string& s, int l, int r) {
        int c = 0;
        while ((l >= 0) && (r < s.length()) && (s[l] == s[r])) {
            ++ c;
            -- l;
            ++ r;
        }
        return c;
    }
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); ++ i) {
            res += count(s, i, i);
            res += count(s, i, i + 1);
        }
        return res;
    }
};
