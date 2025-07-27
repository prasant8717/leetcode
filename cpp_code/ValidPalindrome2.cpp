class Solution {
public:
    bool palindrome(string s, int c, int e) {
        for (; c < e; ++ c) {
            if (s[c] != s[e]) {
                return false;
            }
            -- e;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size() - 1;
        for (int i = 0; i < n - 1; ++ i) {
            if (s[i] != s[n]) {
                bool s1 = palindrome(s, i + 1, n);
                bool s2 = palindrome(s, i, n - 1);
                return s1 || s2;
            }
            -- n;
        }
        return true;
    }
};
