class Solution {
public:
    bool hasSameDigits(string s) {
        int l = s.length();
        while (l > 2) {
            for (int i = 0; i < l - 1; ++ i) {
                s[i] = (s[i] + s[i + 1]) % 10;
            }
            -- l;
        }
        return (s[0] == s[1]);
    }
};
